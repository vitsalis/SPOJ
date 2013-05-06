#include <cstdio>
#include <algorithm>

using namespace std;

struct team {
    int pen, solv, idx;
};

int at[ 100 ][ 10 ], tim[ 100 ][ 10 ];
int up = 1000000;

bool operator <( team a, team b ) {
    if ( a.solv == b.solv ) {
        return a.pen < b.pen;
    }
    return a.solv > b.solv;
}

team array[ 1000 ];

bool check( team save[], int N ) {
    int i;
    for ( i = 0; i < N - 1; ++i ) {
        if ( save[ i ].solv == save[ i + 1 ].solv && save[ i ].pen > save[ i + 1 ].pen ) {
            return false;
        }
        if ( array[ i ].pen == array[ i + 1 ].pen && array[ i ].solv == array[ i + 1 ].solv ) {
            if ( save[ i ].pen < save[ i + 1 ].pen ) {
                return false;
            }
        }
        if ( save[ i ].solv == save[ i + 1 ].solv ) {
            if ( save[ i ].pen == save[ i + 1 ].pen ) {
                if ( array[ i ].pen < array[ i + 1 ].pen ) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    //freopen( "icps.in", "r", stdin );
    //freopen( "icpc.out", "w", stdout );
    int N, P, i, j, c, p, count = 0, hi, lo, l, r, op, clo;
    bool left, right;
    team save[ 1000 ];
    while ( 1 ) {
        ++count;
        scanf( "%d%d", &N, &P );
        if ( N == 0 && P == 0 ) {
            break;
        }
        for ( i = 0; i < N; ++i ) {
            array[ i ].pen = array[ i ].solv = 0;
            array[ i ].idx = i;
            for ( j = 0; j < P; ++j ) {
                at[ i ][ j ] = tim[ i ][ j ] = 0;
                p = -1;
                scanf( "%d%*c%d", &c, &p );
                if ( p == -1 ) {
                    continue;
                }
                at[ i ][ j ] = c - 1;
                tim[ i ][ j ] = p;
                array[ i ].solv += 1;
                array[ i ].pen = array[ i ].pen + p + 20 * ( c - 1 );
            }
        }
        sort( array, array + N );
        lo = 1;
        hi = 3000;
        op = clo = 0;
        for ( ; lo <= hi; ++lo ) {
            for ( i = 0; i < N; ++i ) {
                save[ i ].solv = array[ i ].solv;
                save[ i ].pen = 0;
                for ( j = 0; j < P; ++j ) {
                    save[ i ].pen = save[ i ].pen + tim[ array[ i ].idx ][ j ] + lo * at[ array[ i ].idx ][ j ];
                }
            }
            if ( check( save, N ) ) {
                clo = lo;
                if ( op == 0 ) {
                    op = lo;
                }
            }
        }
        if ( clo == 3000 ) {
            printf( "%d *\n", op );
        }
        else {
            printf( "%d %d\n", op, clo );
        }
    }
    return 0;
}
