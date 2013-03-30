#include <cstdio>
#include <vector>

#define MAX 111060

using namespace std;

vector< int > graph[ MAX ], graphT[ MAX ];
vector< int > sol;
bool visited[ MAX ];
int comp[ MAX ], size[ MAX ];

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
    comp[ S ] = c;
    size[ c ] += 1;
    visited[ S ] = false;
    int i;
    for ( i = 0; i < graphT[ S ].size(); ++i ) {
        if ( visited[ graphT[ S ][ i ] ] ) {
            dfs2( graphT[ S ][ i ], c );
        }
    }
}

int main() {
    int t, N, M, S, i, j, u, v, compon;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d%d", &N, &M, &S );
        sol.clear();
        for ( i = 0; i < MAX; ++i ) {
            visited[ i ] = false;
            comp[ i ] = 0;
            size[ i ] = 0;
            graph[ i ].clear();
            graphT[ i ].clear();
        }
        for ( i = 0; i < S; ++i ) {
            scanf( "%d%d", &u, &v );
            graph[ u ].push_back( v );
            graphT[ v ].push_back( u );
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
        for ( i = 1; i <= N; ++i ) {
            size[ comp[ i ] ] -= 1;
        }
        int pos = -1, m = -1;
        for ( i = 1; i <= N; ++i ) {
            if ( size[ comp[ i ] ] > m ) {
                m = size[ comp[ i ] ];
                pos = i; 
            }
        }
        printf( "%d %d\n", pos, m );
    }
    return 0;
}
