#include <cstdio>
#define MAX 100000

using namespace std;

struct gr {
    int b, e;
};

int beg[ MAX + 1 ], end[ MAX + 1 ], found[ MAX + 1 ];

int sum1( int y ) {
    int res = 0;
    while ( y > 0 ) {
        res += beg[ y ];
        y -= ( y & -y );
    }
    return res;
}

int sum2( int y ) {
    int res = 0;
    while ( y > 0 ) {
        res += end[ y ];
        y -= ( y & -y );
    }
    return res;
}

void add1( int y ) {
    while ( y <= 100000 ) {
        beg[ y ] += 1;
        y += ( y & -y );
    }
}

void add2( int y ) {
    while ( y <= 100000 ) {
        end[ y ] += 1;
        y += ( y & -y );
    }
}

int main() {
    int N, i;
    scanf( "%d", &N );
    gr array[ N ];
    for ( i = 0; i < N; ++i ) {
        scanf( "%d%d", &array[ i ].b, &array[ i ].e );
    }
    for ( i = 0; i < N; ++i ) {
        int i1 = ( sum2( 100000 ) - sum2( array[ i ].b ) ) - ( sum1( 100000 ) - sum1( array[ i ].b - 1 ) );
        int i2 = ( sum2( 100000 ) - sum2( array[ i ].e ) ) - ( sum1( 100000 ) - sum1( array[ i ].e -1 ) );
        if ( i1 > 0 ) {
            i1 -= found[ array[ i ].b ];
        }
        if ( i2 ) {
            i2 -= found[ array[ i ].e ];
        }
        printf( "%d\n", i2 + i1 );
        found[ array[ i ].b ] += i1;
        found[ array[ i ].e ] += i2;
        add1( array[ i ].b );
        add2( array[ i ].e );
    }
    return 0;
}
