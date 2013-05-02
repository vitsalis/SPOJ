#include <cstdio>
#include <algorithm>

using namespace std;

long long bsearch( int m, int N, int cows, long long* array ) {
    long long lo = 0, hi = m, mid, cur;
    int i, j;
    bool changed;
    while ( lo < hi ) {
        mid = lo + ( hi - lo + 1 ) / 2;
        cur = 0;
        for ( i = 0; i < N; ++i ) {
            j = array[ i ];
            ++cur;
            changed = false;
            while ( array[ i ] < j + mid ) {
                ++i;
                changed = true;
            }
            if ( changed ) {
                --i;
            }
        }
        if ( cur < cows ) {
            hi = mid - 1;
        }
        else {
            lo = mid;
        }
    }
    return lo;
}

int main() {
    int t, i, N, cows;
    long long array[ 100000 ];
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &N, &cows );
        for ( i = 0; i < N; ++i ) {
            scanf( "%lld", array + i );
        }
        sort( array, array + N );
        printf( "%lld\n", bsearch( array[ N - 1 ] - array[ 0 ], N, cows, array ) );
    }
    return 0;
}
