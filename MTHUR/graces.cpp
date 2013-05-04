#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 20000
#define INF 200000000

using namespace std;

struct lval {
    int val, sum;
};

int a[ MAX ], b[ MAX ], graces[ MAX * 5 ], N;

int f( int cur ) {
    int res = 0, i;
    for ( i = 0; i < N; ++i ) {
        res += fabs( a[ i ] - ( b[ i ] + cur ) );
    }
    return res;
}

int main() {
    int t, i, m, hi, lo, l, r;
    int mini, val, lsum, rsum;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &N );
        for ( i = 0; i < N; ++i ) {
            scanf( "%d", a + i );
        }
        for ( i = 0; i < N; ++i ) {
            scanf( "%d", b + i );
        }
        scanf( "%d", &m );
        for ( i = 0; i < m; ++i ) {
            scanf( "%d", graces + i );
        }
        sort( graces, graces + m );
        hi = m - 1;
        lo = 0;
        mini = INF;
        while ( hi - lo + 1 > 3 ) {
            l = ( lo * 2 + hi ) / 3;
            r = ( lo + hi * 2 ) / 3;
            if ( f( graces[ l ] ) > f( graces[ r ] ) ) {
                lo = l;
            }
            else {
                hi = r;
            }
        }
        for ( i = lo; i <= hi; ++i ) {
            if ( mini > f( graces[ i ] ) ) {
                mini = f( graces[ i ] );
                val = graces[ i ];
            }
        }
        printf( "%d\n", val );
    }
    return 0;
}
