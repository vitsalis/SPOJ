#include <cstdio>
#include <vector>
#include <queue>

#define MAXN 5000

using namespace std;

vector< int > graph[ MAXN + 1 ], graphT[ MAXN + 1 ], sorted;
bool visited[ MAXN + 1 ];
int comp[ MAXN + 1 ], sol[ MAXN + 1 ];
int N, M;

void init( int N ) {
    for ( int i = 0; i <= N; ++i ) {
        graph[ i ].clear();
        graphT[ i ].clear();
        visited[ i ] = false;
    }
	sorted.clear();
}

void dfs1( int S ) {
    visited[ S ] = true;
    int i;
    for ( i = 0; i < graph[ S ].size(); ++i ) {
        if ( !visited[ graph[ S ][ i ] ] ) {
            dfs1( graph[ S ][ i ] );
        }
    }
    sorted.push_back( S );
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
    int i, j, u, v, compon;
    while ( 1 ) {
        scanf( "%d", &N );
        if ( N == 0 ) {
            break;
        }
        scanf( "%d", &M );
        init( N );
        for ( i = 0; i < M; ++i ) {
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
        for ( i = sorted.size() - 1; i >= 0; --i ) {
            if ( visited[ sorted[ i ] ] ) {
                dfs2( sorted[ i ], compon++ );
                sol[ compon - 1 ] = true;
            }
        }
        for ( i = 1; i <= N; ++i ) {
            for ( j = 0; j < graph[ i ].size(); ++j ) {
                if ( comp[ i ] != comp[ graph[ i ][ j ] ] ) {
                    sol[ comp[ i ] ] = false;
                    break;
                }
            }
        }
        for ( i = 1; i <= N; ++i ) {
            if ( sol[ comp[ i ] ] ) {
                printf( "%d ", i );
            }
        }
        printf( "\n" );
    }
    
    return 0;
}
