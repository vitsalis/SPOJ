#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int found[ 100001 ];
    int t, X, N, array[ 100000 ], i, j, k;
    long long int count;
    scanf( "%d", &t );
    for ( k = 1; k <= t; ++k ) {
        scanf( "%d%d", &X, &N );
        for ( i = 0; i <= 100000; ++i ) {
            found[ i ] = 0;
        }
        count = 0;
        for ( i = 0; i < N; ++i ) {
            scanf( "%d", array + i );
            if ( X >= array[ i ] ) {
                count += found[ X - array[ i ] ];
            }
            found[ array[ i ] ] += 1;
        }
        printf( "%d. %lld\n", k, count );
    }
    return 0;
}
