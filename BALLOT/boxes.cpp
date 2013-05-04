#include <cstdio>
#define INF 5000000
#define MAX 500000

using namespace std;

int array[ MAX ], N, B;

int ned( int dist ) {
    int ans = 0, i;
    for ( i = 0; i < N; ++i ) {
        if ( array[ i ] > dist ) {
            ans = ans + ( array[ i ] / dist );
            if ( array[ i ] % dist > 0 ) {
                ++ans;
            }
        }
        else {
            ++ans;
        }
    }
    return ans;
}

int bsearch( int lo, int hi ) {
    int mid;
    lo = 1;
    while ( lo < hi ) {
        mid = lo + ( hi - lo ) / 2;
        if ( ned( mid ) <= B ) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    int ma, mi, i;
    while ( 1 ) {
        scanf( "%d%d", &N, &B );
        if ( N == -1 && B == -1 ) {
            break;
        }
        mi = INF;
        ma = 0;
        for ( i = 0; i < N; ++i ) {
            scanf( "%d", array + i );
            if ( array[ i ] < mi ) {
                mi = array[ i ];
            }
            if ( array[ i ] > ma ) {
                ma = array[ i ];
            }
        }
        printf( "%d\n", bsearch( mi, ma ) );
    }
    return 0;
}
