#include <cstdio>
#include <vector>
#include <queue>

#define MAX 1000001
const long long int INF = 1000000001;

using namespace std;

struct edge {
    int v;
    int w;
};

bool operator <( edge a, edge b ) {
    return a.w < b.w;
}

vector< edge > *graph, *graphT;

void dijkstra( vector< edge > graph[], long int* dist ) {
    priority_queue< edge > q;
    dist[ 1 ] = 0;
    q.push( ( edge ) { 1, 0 } );
    while ( !q.empty() ) {
        edge p = q.top();
        q.pop();
        for ( int i = 0; i < graph[ p.v ].size(); ++i ) {
            edge k = graph[ p.v ][ i ];
            if ( dist[ p.v ] + k.w < dist[ k.v ] ) {
                dist[ k.v ] = dist[ p.v ] + k.w;
                q.push( k );
            }
        }
    }
}

int main() {
    int t, N, M, u, v, i;
    long int dist[ MAX ], distT[ MAX ], w;
    graph = new vector< edge >[ MAX ]; 
    graphT = new vector< edge >[ MAX ];
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &N, &M );
        for ( i = 1; i <= N; ++i ) {
            graph[ i ].clear();
            graphT[ i ].clear();
            dist[ i ] = distT[ i ] = INF;
        }
        for ( i = 0; i < M; ++i ) {
            scanf( "%d%d%ld", &u, &v, &w );
            graph[ u ].push_back( ( edge ) { v, w } );
            graphT[ v ].push_back( ( edge ) { u, w } );
        }
        dijkstra( graph, dist );
        dijkstra( graphT, distT );
        long long int cost = 0;
        for ( i = 1; i <= N; ++i ) {
            cost = cost + dist[ i ] + distT[ i ];
        }
        printf( "%lld\n", cost );
    }
    return 0;
}
