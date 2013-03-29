#include <cstdio>
#include <algorithm>
#include <vector>

#define MAXN 50000

using namespace std;

vector< int > graph[ MAXN + 1 ], graphT[ MAXN + 1 ], sol;
bool visited[ MAXN + 1 ];
int comp[ MAXN + 1 ], in[ MAXN + 1 ];

void dfs1( int S ) {
    visited[ S ] = true;
    int i;
    for ( i = 0; i < graph[ S ].size(); ++i ) {
        if ( !visited[ graph[ S ][ i ] ] ) {
            dfs1( graph[ S ][ i ] );
        }
    }
    sol.push_back( S );
}

void dfs2( int S, int c ) {
    visited[ S ] = false;
    comp[ S ] = c;
    int i;
    for ( i = 0; i < graphT[ S ].size(); ++i ) {
        if ( visited[ graphT[ S ][ i ] ] ) {
            dfs2( graphT[ S ][ i ], c );
        }
    }
}

int main() {
    int t, i, j, N, lim, v, compon;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &N );
        for ( i = 1; i <= N; ++i ) {
            visited[ i ] = false;
            graph[ i ].clear();
            graphT[ i ].clear();
            in[ i ] = 0;
        }
        for ( i = 1; i <= N; ++i ) {
            scanf( "%d", &lim );
            for ( j = 0; j < lim; ++j ) {
                scanf( "%d", &v );
                graph[ v ].push_back( i );
                graphT[ i ].push_back( v );
            }
        }
        for ( i = 1; i <= N; ++i ) {
            if ( !visited[ i ] ) {
                dfs1( i );
            }
        }
        compon = 0;
        for ( i = sol.size() - 1; i >= 0; --i ) {
            if ( visited[ sol[ i ] ] ) {
                dfs2( sol[ i ], compon++ );
            }
        }
        lim = compon;
        for ( i = 1; i <= N; ++i ) {
            for ( j = 0; j < graph[ i ].size(); ++j ) {
                if ( comp[ i ] != comp[ graph[ i ][ j ] ] ) {
                    in[ comp[ graph[ i ][ j ] ] ] += 1;
                }
            }
        }
        int count = 0;
        for ( i = 0; i < lim; ++i ) {
            if ( in[ i ] == 0 ) {
                ++count;
            }
        }
        if ( count > 1 ) {
            printf( "0\n" );
        }
        else {
            count = 0;
            for ( i = 1; i <= N; ++i ) {
                if ( in[ comp[ i ] ] == 0 ) {
                    ++count;
                }
            }
            printf( "%d\n", count );
        }
    }
    return 0;
}
