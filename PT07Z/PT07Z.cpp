#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dist[ 10005 ];
int maxa = 0;

void bfs( vector< int > graph[], int u, int N ) {
	bool visited[ N + 1 ];
	int i;
	for ( i = 0; i < 10005; ++i ) {
		dist[ i ] = 0;
	}
	for ( i = 0; i <= N; ++i ) {
		visited[ i ] = false;
	}
	queue< int > q;
	q.push( u );
	int max = 0;
	while ( !q.empty() ) {
		int p = q.front();
		q.pop();
		visited[ p ] = true;
		for ( i = 0; i < graph[ p ].size(); ++i ) {
			int k = graph[ p ][ i ];
			if ( !visited[ k ] ) {
				q.push( k );
				if ( dist[ k ] < dist[ p ] + 1 ) {
					dist[ k ] = dist[ p ] + 1;
					if ( max < dist[ k ] ) {
						max = dist[ k ];
					}
				}
			}
		}
	}
	if ( max > maxa ) {
		maxa = max;
	}
}

int main() {
	int N;
	fscanf( stdin, "%d", &N );
	if ( N == 1 ) {
		fprintf( stdout, "1\n" );
		return 0;
	}
	vector< int > graph[ N + 1 ];
	int i;
	int u, v, f;
	fscanf( stdin, "%d %d", &u, &v );
	graph[ u ].push_back( v );
	graph[ v ].push_back( u );
	f = u;
	for ( i = 1; i < N - 1; ++i ) {
		fscanf( stdin, "%d %d", &u, &v );
		graph[ u ].push_back( v );
		graph[ v ].push_back( u );
	}

	int max = 0;
	bfs( graph, 1, N );
	int pos;
	for ( i = 1; i <= N; ++i ) {
		if ( dist[ i ] > max ) {
			max = dist[ i ];
			pos = i;
		}
	}
	bfs( graph, pos, N );
	fprintf( stdout, "%d\n", maxa );

	return 0;
}
