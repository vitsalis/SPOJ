#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int N, M, i, lim, j, v;
    queue< int > q, n;
    scanf( "%d%d", &N, &M );
    vector< int > graph[ N + 1 ];
    int in[ N + 1 ], P[ N + 1 ];
    for ( i = 0; i <= N; ++i ) {
        in[ i ] = 0;
        P[ i ] = 0;
    }
    for ( i = 1; i <= M; ++i ) {
        scanf( "%d", &lim );
        for ( j = 0; j < lim; ++j ) {
            scanf( "%d", &v );
            in[ v ] += 1;
            graph[ i ].push_back( v );
        }
    }
    int boss = -1;
    for ( i = 1; i <= N; ++i ) {
        if ( in[ i ] == 0 ) {
            q.push( i );
        }
    }
    int prevpop = 0;
    while ( !q.empty() ) {
        int p = q.front();
        q.pop();
        P[ p ] = prevpop;
        for ( i = 0; i < graph[ p ].size(); ++i ) {
            int k = graph[ p ][ i ];
            in[ k ] -= 1;
            if ( in[ k ] == 0 ) {
                q.push( k );
            }
        }
        prevpop = p;
    }
    for ( i = 1; i <= N; ++i ) {
        printf( "%d\n", P[ i ] );
    }
    return 0;
}
