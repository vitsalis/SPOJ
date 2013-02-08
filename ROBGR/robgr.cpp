#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

const int MOD = (2LL << 30LL) - 1;

struct cord {
	int x;
	int y;
};

bool bfs( bool array[][ 1000 ], int N ) {
	bool visited[ N + 1 ][ N + 1 ];
	int i, j;
	for ( i = 0; i <= N; ++i ) {
		for ( j = 0; j <= N; ++j ) {
			visited[ i ][ j ] = false;
		}
	}
	stack< cord > q;
	q.push( ( cord ) { 0, 0 } );
	visited[ 0 ][ 0 ] = true;
	while ( !q.empty() ) {
		cord p = q.top();
		q.pop();
		visited[ p.x ][ p.y ] = true;
		if ( p.x - 1 >= 0 && array[ p.x - 1 ][ p.y ] == 1 && !visited[ p.x - 1 ][ p.y ] ) {
			q.push( ( cord ) { p.x - 1, p.y } );
		}
		if ( p.y - 1 >= 0 && array[ p.x ][ p.y - 1 ] == 1 && !visited[ p.x ][ p.y - 1 ] ) {
			q.push( ( cord ) { p.x, p.y - 1 } );
		}
		if ( p.x + 1 < N && array[ p.x + 1 ][ p.y ] == 1 && !visited[ p.x + 1 ][ p.y ] ) {
			q.push( ( cord ) { p.x + 1, p.y } );
		}
		if ( p.y + 1 < N && array[ p.x ][ p.y + 1 ] == 1 && !visited[ p.x ][ p.y + 1 ] ) {
			q.push( ( cord ) { p.x, p.y + 1 } );
		}
	}
	return visited[ N - 1 ][ N - 1 ];
}

int main() {
	int N;
	scanf( "%d", &N );
	bool array[ 1000 ][ 1000 ];
	long int dist[ N ][ N ];
	char c;
	int i, j;
	scanf( "%*c" );
	for ( i = 0; i < N; ++i ) {
		for ( j = 0; j < N; ++j ) {
			scanf( "%c", &c );
			dist[ i ][ j ] = 0;
			if ( c == '.' ) {
				array[ i ][ j ] = 1;
			}
			else {
				array[ i ][ j ] = 0;
			}
		}
		if ( i + 1 < N ) {
			scanf( "%*c" );
		}
	}
	dist[ 0 ][ 0 ] = 1;
	for ( i = 0; i < N; ++i ) {
		for ( j = 0; j < N; ++j ) {
			if ( array[ i ][ j ] == 0 ) {
				continue;
			}
			if ( i - 1 >= 0 && j - 1 >= 0 && array[ i - 1 ][ j ] == 1 && array[ i ][ j - 1 ] == 1 ) {
				dist[ i ][ j ] = ( (long long)dist[ i - 1 ][ j ] + dist[ i ][ j - 1 ] ) % MOD;
			}
			else if ( i - 1 >= 0 && array[ i - 1 ][ j ] == 1 ) {
				dist[ i ][ j ] = ( long long )dist[ i - 1 ][ j ] % MOD;
			}
			else if ( j - 1 >= 0 && array[ i ][ j - 1 ] == 1 ) {
				dist[ i ][ j ] = ( long long )dist[ i ][ j - 1 ] % MOD;
			}
		}
	}
	if ( dist[ N - 1 ][ N - 1 ] > 0 ) {
		printf( "%ld\n", dist[ N - 1 ][ N - 1 ] );
	}
	else {
		if ( bfs( array, N ) ) {
			printf( "THE GAME IS A LIE\n" );
		}
		else {
			printf( "INCONCEIVABLE\n" );
		}
	}
	return 0;
}
