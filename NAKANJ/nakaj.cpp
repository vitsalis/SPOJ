#include <cstdio>
#include <queue>

using namespace std;

struct cord {
	int x;
	int y;
};

const int INF = 1000000;
const int N = 8;
int xx, yy;

char ab[ 9 ] = "abcdefgh";

bool check( int x, int y, bool visited[][ 8 ], int dist[][ 8 ] ) {
	if ( x < 0 || x >= N ) return false;
	if ( y < 0 || y >= N ) return false;
	if ( visited[ x ][ y ] ) return false;
	if ( dist[ xx ][ yy ] + 1 >= dist[ x ][ y ] ) return false;
	return true;
}

void compute( cord source, cord dest ) {
	bool visited[ N ][ N ];
	int dist[ N ][ N ], i, j;
	for ( i = 0; i < N; ++i ) {
		for ( j = 0; j < N; ++j ) {
			visited[ i ][ j ] = false;
			dist[ i ][ j ] = INF;
		}
	}
	queue< cord > q;
	q.push( source );
	dist[ source.x ][ source.y ] = 0;
	visited[ source.x ][ source.y ] = true;

	while ( !q.empty() ) {
		cord p = q.front();
		q.pop();
		xx = p.x, yy = p.y;
		visited[ xx ][ yy ] = true;
		if ( check( xx - 1, yy + 2, visited, dist ) ) {
			q.push( ( cord ) { xx - 1, yy + 2 } );
			dist[ xx - 1 ][ yy + 2 ] = dist[ xx ][ yy ] + 1;
		}
		if ( check( xx + 1, yy + 2, visited, dist ) ) {
			q.push( ( cord ) { xx + 1, yy + 2 } );
			dist[ xx + 1 ][ yy + 2 ] = dist[ xx ][ yy ] + 1;
		}
		if ( check( xx - 1, yy - 2, visited, dist ) ) {
			q.push( ( cord ) { xx - 1, yy - 2 } );
			dist[ xx - 1 ][ yy - 2 ] = dist[ xx ][ yy ] + 1;
		}
		if ( check( xx + 1, yy - 2, visited, dist ) ) {
			q.push( ( cord ) { xx + 1, yy - 2 } );
			dist[ xx + 1 ][ yy - 2 ] = dist[ xx ][ yy ] + 1;
		}
		if ( check( xx - 2, yy + 1, visited, dist ) ) {
			q.push( ( cord ) { xx - 2, yy + 1 } );
			dist[ xx - 2 ][ yy + 1 ] = dist[ xx ][ yy ] + 1;
		}
		if ( check( xx + 2, yy + 1, visited, dist ) ) {
			q.push( ( cord ) { xx + 2, yy + 1 } );
			dist[ xx + 2 ][ yy + 1 ] = dist[ xx ][ yy ] + 1;
		}
		if ( check( xx - 2, yy - 1, visited, dist ) ) {
			q.push( ( cord ) { xx - 2, yy - 1 } );
			dist[ xx - 2 ][ yy - 1 ] = dist[ xx ][ yy ] + 1;
		}
		if ( check( xx + 2, yy - 1, visited, dist ) ) {
			q.push( ( cord ) { xx + 2, yy - 1 } );
			dist[ xx + 2 ][ yy - 1 ] = dist[ xx ][ yy ] + 1;
		}
	}
	printf( "%d\n", dist[ dest.x ][ dest.y ] );
}

int main() {
	int t, i;
	char a[ 3 ], b[ 3 ];
	cord source, dest;
	scanf( "%d", &t );
	while ( t > 0 ) {
		scanf( "%s%s", a, b );
		for ( i = 0; i < N; ++i ) {
			if ( ab[ i ] == a[ 0 ] ) {
				source.x = i;
			}
			if ( ab[ i ] == b[ 0 ] ) {
				dest.x = i;
			}
		}
		source.y = ( a[ 1 ] - '0' ) - 1;
		dest.y = ( b[ 1 ] - '0' ) - 1;

		compute( source, dest );

		--t;
	}

	return 0;
}
