#include <cstdio>
#include <queue>

using namespace std;

int dist[ 1000001 ];
int count = 0;

bool bfs( int N, int S, int T, int u, int d ) {
	bool visited[ N + 2 ];
	int i, p;
	for ( i = 0; i <= N + 1; ++i ) {
		visited[ i ] = false;
		dist[ i ] = -1;
	}
	dist[ S ] = 0;
	queue<int> q;
	q.push( S );
	while ( !q.empty() ) {
		p = q.front();
		q.pop();
		if ( !visited[ p ] ) {
			visited[ p ] = true;
			if ( p == T ) {
				break;
			}
			if ( p + u <= N && !visited[ p + u ] ) {
				q.push( p + u );
				dist[ p + u ] = dist[ p ] + 1;
			}
			if ( p - d > 0 && !visited[ p - d ] ) {
				dist[ p - d ] = dist[ p ] + 1;
				q.push( p - d );
			}
		}
	}
	return visited[ T ];
}

int main() {
	int N, S, T, U, D;
	fscanf( stdin, "%d%d%d%d%d", &N, &S, &T, &U, &D );
	bfs( N, S, T, U, D );
	if ( dist[ T ] == -1 ) {
		fprintf( stdout, "use the stairs\n" );
	}
	else {
		fprintf( stdout, "%d\n", dist[ T ] );
	}

	return 0;
}
