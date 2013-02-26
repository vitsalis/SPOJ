#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void init( bool array[], int N ) {
    for ( int i = 0; i <= N; ++i ) {
        array[ i ] = false;
    }
}

void dfs( vector< int > tree[], bool visited[], int dp[][ 2 ], int N, int S ) {
    visited[ S ] = true;
    int i;
    int ma, mi;
    ma = mi = 0;
    for ( i = 0; i < tree[ S ].size(); ++i ) {
        if ( !visited[ tree[ S ][ i ] ] ) {
            dfs( tree, visited, dp, N, tree[ S ][ i ] );
            ma += dp[ tree[ S ][ i ] ][ 1 ];
            mi += min( dp[ tree[ S ][ i ] ][ 1 ], dp[ tree[ S ][ i ] ][ 0 ] );
        }
    }
    dp[ S ][ 0 ] = ma;
    dp[ S ][ 1 ] = mi + 1;
}

int main() {
    int N, i, u, v;
    scanf( "%d", &N );
    vector< int > tree[ N + 1 ];
    for ( i = 0; i < N - 1; ++i ){
        scanf( "%d%d", &u, &v );
        tree[ u ].push_back( v );
        tree[ v ].push_back( u );
    }
    int dp[ N + 1 ][ 2 ];
    bool visited[ N + 1 ];
    init( visited, N );
    dfs( tree, visited, dp, N, 1 );
    printf( "%d\n", min( dp[ 1 ][ 0 ], dp[ 1 ][ 1 ] ) );

    return 0;
}
