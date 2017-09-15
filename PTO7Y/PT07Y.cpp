#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool bfs( vector< int > graph[], int u, int N ) {
	bool visited[ N + 1 ];
	int i;
	for ( i = 0; i <= N; ++i ) {
		visited[ i ] = false;
	}
	queue< int > q;
	q.push( u );
	int p, k, count = 0;
	while ( !q.empty() ) {
		p = q.front();
		q.pop();
		visited[ p ] = true;
		for ( i = 0; i < graph[ p ].size(); ++i ) {
			k = graph[ p ][ i ];
			if ( visited[ k ] ) {
				return false;
			}
			else {
				q.push( k );
			}
		}
		++count;
	}
	if ( count != N ) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	int N, M;
	fscanf( stdin, "%d%d", &N, &M );
	vector< int > graph[ N + 1 ];
	int i, u, v;
	for ( i = 0; i < M; ++i ) {
		fscanf( stdin, "%d%d", &u, &v );
		graph[ u ].push_back( v );
		graph[ v ].push_back( u ); //This line is added as we're asked to implement undirected graph.
	}
	if ( bfs( graph, 1, N ) ) {
		fprintf( stdout, "YES\n" );
	}
	else {
		fprintf( stdout, "NO\n" );
	}

	return 0;
}
