#include <cstdio>
#include <algorithm>

using namespace std;

struct coder {
    int b, e, idx;
};

bool operator <( coder a, coder b ) {
    if ( a.b == b.b ) {
        return a.e < b.e;
    }
    return a.b < b.b;
}

int bit[ 100001 ];

void add( int y ) {
    while ( y <= 100000 ) {
        bit[ y ] += 1;
        y += ( y & -y );
    }
}

int sum( int y ) {
    int res = 0;
    while ( y > 0 ) {
        res += bit[ y ];
        y -= ( y & -y );
    }
    return res;
}

int main() {
    int N, i, prevb, preve;
    scanf( "%d", &N );
    coder array[ N ];
    int ans[ N ];
    for ( i = 0; i < N; ++i ) {
        scanf( "%d%d", &array[ i ].b, &array[ i ].e );
        array[ i ].idx = i;
    }
    sort( array, array + N );
    prevb = preve = 0;
    for ( i = 0; i < N; ++i ) {
        if ( prevb != array[ i ].b || preve != array[ i ].e ) {
            ans[ array[ i ].idx ] = sum( array[ i ].e );
        }
        else {
            ans[ array[ i ].idx ] = sum( array[ i ].e ) - 1;
        }
        add( array[ i ].e );
        prevb = array[ i ].b;
        preve = array[ i ].e;
    }
    for ( i = 0; i < N; ++i ) {
        printf( "%d\n", ans[ i ] );
    }
    return 0;
}
