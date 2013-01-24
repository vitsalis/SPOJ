#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define INF 1000000;

struct edge {
	int u;
	int w;
};

bool operator <( edge a, edge b ) {
	return a.w < b.w;
}

void dijkstra( vector< edge > graph[], int dist[], int N, int s ) {
	dist[ s ] = 0;
	priority_queue< edge > q;
	q.push( ( edge ) { s, 0 } );

	while ( !q.empty() ) {
		edge p = q.top();
		q.pop();
		for ( int i = 0; i < graph[ p.u ].size(); ++i ) {
			int u = p.u;
			int v = graph[ p.u ][ i ].u;
			if ( dist[ u ] + graph[ p.u ][ i ].w < dist[ v ] ) {
				dist[ v ] = dist[ u ] + graph[ p.u ][ i ].w;
				q.push( graph[ p.u ][ i ] );
			}
		}
	}
}

int main() {
	int t;
	int N, E;
	int S, T;
	int u, v, w, i;
	scanf( "%d", &t );
	while ( t > 0 ) {
		scanf( "%d%d", &N, &E );
		vector< edge > graph[ N + 1 ];
		int dist[ N + 1 ];
		for ( i = 0; i < E; ++i ) {
			scanf( "%d%d%d", &u, &v, &w );
			graph[ u ].push_back( ( edge ) { v, w } );
		}
		for ( i = 0; i <= N; ++i ) {
			dist[ i ] = INF;
		}
		scanf( "%d%d", &S, &T );
		dijkstra( graph, dist, N, S );
		if ( dist[ T ] != 1000000 ) {
			printf( "%d\n", dist[ T ] );
		}
		else {
			printf( "NO\n" );
		}

		--t;
	}
	return 0;
}
