#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 10000

using namespace std;

struct build {
    int h, c;
};

bool operator <( build a, build b ) {
    if ( a.h == b.h ) {
        return a.c < b.c;
    }
    return a.h < b.h;
}

int N;
build array[ 2 * MAX + 1 ];

int f( int pos ) {
    int i;
    int cost = 0;
    for ( i = 0; i < N; ++i ) {
        cost = cost + fabs( array[ i ].h - array[ pos ].h ) * array[ i ].c;
    }
    return cost;
}

int main() {
    int t, i, hi, lo, l, r;
    int mini, cur;
    scanf( "%d", &t );
    while ( t-- ) { 
        scanf( "%d", &N );
        for ( i = 0; i < N; ++i ) {
            scanf( "%d", &array[ i ].h );
        }
        for ( i = 0; i < N; ++i ) {
            scanf( "%d", &array[ i ].c );
        }
        lo = 0;
        hi = N - 1;
        sort( array, array + N );
        while ( hi - lo + 1 > 3 ) {
            l = ( lo * 2 + hi ) / 3;
            r = ( lo + hi * 2 ) / 3;
            if ( f( l ) < f( r ) ) {
                hi = r;
            }
            else {
                lo = l;
            }
        }
        mini = f( lo );
        for ( i = lo + 1; i <= hi; ++i ) {
            mini = min( mini, f( i ) );
        }
        printf( "%d\n", mini );
    }
    return 0;
}
