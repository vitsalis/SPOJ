#include <cstdio>
#include <queue>

using namespace std;

struct edge {
	int v;
	int w;
};

bool operator <( edge a, edge b ) {
	return a.w < b.w;
}

#define INF 10000000

int dist[ 1000001 ];

void dijkstra( vector< edge > graph[], int N, int S, int T ) {
	int i;

	for ( i = 0; i <= N; ++i ) {
		dist[ i ] = INF;
	}
	priority_queue< edge > q;
	q.push( ( edge ) { S, 0 } );
	dist[ S ] = 0;
	while ( !q.empty() ) {
		edge p = q.top();
		q.pop();

		for ( i = 0; i < graph[ p.v ].size(); ++i ) {
			edge k = graph[ p.v ][ i ];
			if ( dist[ p.v ] + k.w < dist[ k.v ] ) {
				dist[ k.v ] = dist[ p.v ] + k.w;
				q.push( k );
			}
		}
	}
	if ( dist[ T ] != INF ) {
		printf( "%d\n", dist[ T ] );
	}
	else {
		printf( "NONE\n" );
	}
}

int main() {
	int t, N, m, s, T;
	int u, v, w, i;
	scanf( "%d", &t );

	while ( t > 0 ) {
		scanf( "%d%d%d%d", &N, &m, &s, &T );
		vector< edge > graph[ N + 1 ];

		for ( i = 0; i < m; ++i ) {
			scanf( "%d%d%d", &u, &v, &w );
			graph[ u ].push_back( ( edge ) { v, w } );
			graph[ v ].push_back( ( edge ) { u, w } );
		}
		dijkstra( graph, N, s, T );

		--t;
	}

	return 0;
}
