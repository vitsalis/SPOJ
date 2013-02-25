#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

struct r {
    int first;
    int second;
};

int main() {
    int N;
    scanf( "%d", &N );
    r rect [ N + 1 ];
    int dp[ N + 1 ][ 2 ], i, u, v;

    for ( i = 1; i <= N; ++i ){
        scanf( "%d%d", &u, &v );
        rect[ i ].first = u;
        rect[ i ].second = v;
    }

    dp[ 1 ][ 0 ] = rect[ 1 ].first;
    dp[ 1 ][ 1 ] = rect[ 1 ].second;

    for ( i = 2; i <= N; ++i ) {
        dp[ i ][ 0 ] = rect[ i ].first +  max( dp[ i - 1 ][ 0 ] + abs( rect[ i ].second - rect[ i - 1 ].second ), dp[ i - 1 ][ 1 ] + abs( rect[ i - 1 ].first - rect[ i ].second ) );
        dp[ i ][ 1 ] = rect[ i ].second + max( dp[ i - 1 ][ 0 ] + abs( rect[ i ].first - rect[ i - 1 ].second ), dp[ i - 1 ][ 1 ] + abs( rect[ i ].first - rect[ i - 1 ].first ) );
    }

    printf( "%d\n", max( dp[ N ][ 0 ], dp[ N ][ 1 ] ) );

    return 0;
}
