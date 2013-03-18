#include <cstdio>
#include <vector>
#include <queue>

#define INF 1000000

using namespace std;

struct edge {
    int v;
    int w;
};

bool operator <( edge a, edge b ) {
    return a.w < b.w;
}

void dijkstra( vector< edge > graph[], int dist[], int S, int T, int N ) {
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
}

int main() {
    int N, S, T, M, u, v, w;
    scanf( "%d%d%d%d", &N, &S, &T, &M );
    vector< edge > graph[ N + 1 ];
    int dist[ N + 1 ], count = 0, i;
    for ( i = 0; i < M; ++i ) {
        scanf( "%d%d%d", &u, &v, &w );
        graph[ u ].push_back( ( edge ) { v, w } );
    }
    for ( i = 1; i <= N; ++i ) {
        dijkstra( graph, dist, i, S, N );
        if ( dist[ S ] <= T ) {
            ++count;
        }
    }
    printf( "%d\n", count );
    return 0;
}
