#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;

struct edge {
    int v, a, b;
};

int dist[ 100001 ], dist2[ 100001 ], dist3[ 100001 ], cost = 0;

void init( int S, vector< edge > graph[], bool visited[] ) {
    int i;
    visited[ S ] = true;
    for ( i = 0; i < graph[ S ].size(); ++i ) {
        edge k = graph[ S ][ i ];
        if ( !visited[ k.v ] ) {
            dist[ k.v ] = dist[ S ] + k.a;
            dist2[ k.v ] = dist[ k.v ];
            dist3[ k.v ] = dist3[ S ] + k.b;
            init( k.v, graph, visited );
        }
    }
}

int dfs2( vector< edge > graph[], bool visited[], int mid, int S, int possi ) {
    visited[ S ] = true;
    int i, del, rem = 0;
    bool vis = false;
    for ( i = 0; i < graph[ S ].size(); ++i ) {
        edge k = graph[ S ][ i ];
        if ( !visited[ k.v ] ) {
            vis = true;
            del = dfs2( graph, visited, mid, k.v, possi + k.a - k.b );
            if ( del > 0 ) {
                if ( del > possi ) {
                    int p = del - possi; 
                    del = possi;
                    cost += p;
                }
                rem = max( del, rem );
            }
        }
    }
    if ( !vis ) {
        if ( dist[ S ] > mid ) {
            return dist[ S ] - mid;
        }
    }
    return rem;
}

void dfs1( vector< edge > graph[], int mid, int N ) {
    bool visited[ 100001 ];
    int i, del;
    for ( i = 0; i <= N; ++i ) {
        visited[ i ] = false;
    }
    visited[ 1 ] = true;
    for ( i = 0; i < graph[ 1 ].size(); ++i ) {
        edge k = graph[ 1 ][ i ];
        del = dfs2( graph, visited, mid, k.v, k.a - k.b );
        if ( del > 0 ) {
            if ( k.a - k.b >= del ) {
                cost += del;
            }
            else {
                cost += ( k.a - k.b );
                del -= ( k.a - k.b );
            }
        }
    }
}

int main() {
    int N, K, hi = 0, lo = 0, u, v, a, b, i, mid;
    scanf( "%d%d", &N, &K );
    vector< edge > graph[ N + 1 ];
    bool visited[ N + 1 ];
    for ( i = 0; i < N - 1; ++i ) {
        scanf( "%d%d%d%d", &u, &v, &a, &b );
        graph[ u ].push_back( ( edge ) { v, a, b } );
        graph[ v ].push_back( ( edge ) { u, a, b } );
    }
    for ( i = 0; i <= N; ++i ) {
        visited[ i ] = false;
    }
    dist[ 1 ] = 0;
    init( 1, graph, visited );
    for ( i = 1; i <= N; ++i ) {
        if ( dist[ i ] > hi ) {
            hi = dist[ i ];
        }
        if ( dist3[ i ] > lo ) {
            lo = dist3[ i ];
        }
    }
    /*for ( i = 1; i <= N; ++i ) {
        printf( "%d %d\n", i, dist[ i ] );
    }*/
    //printf( "%d %d\n", hi, lo );
    while ( lo < hi ) {
        mid = lo + ( hi - lo ) / 2;
        for ( i = 1; i <= N; ++i ) {
            dist[ i ] = dist2[ i ];
        }
        cost = 0;
        dfs1( graph, mid, N );
        if ( cost <= K ) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    printf( "%d\n", lo );
    return 0;
}
