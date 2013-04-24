#include <cstdio>
#include <algorithm>

using namespace std;

struct req {
    int val, l, r, idx;
    bool t;
};

bool operator <( req a, req b ) {
    if ( a.val == b.val ) {
        return a.t < b.t;
    }
    return a.val < b.val;
}

int N, Q, bit[ 30001 ];

int sum( int y ) {
    int res = 0;
    while ( y > 0 ) {
        res += bit[ y ];
        y -= ( y & -y );
    }
    return res;
}

void add( int y ) {
    while ( y <= 30000 ) {
        bit[ y ] += 1;
        y += ( y & -y );
    }
}

int main() {
    req requests[ 230000 ];
    int i;
    scanf( "%d", &N );
    for ( i = 0; i < N; ++i ) {
        scanf( "%d", &requests[ i ].val );
        requests[ i ].idx = i + 1;
        requests[ i ].t = 0;
    }
    scanf( "%d", &Q );
    for ( i = N; i < N + Q; ++i ) {
        scanf( "%d%d%d", &requests[ i ].l, &requests[ i ].r, &requests[ i ].val );
        requests[ i ].idx = i - N; 
        requests[ i ].t = 1;
    }
    int ans[ Q ];
    sort( requests, requests + N + Q );
    for ( i = 0; i < N + Q; ++i ) {
        if ( requests[ i ].t ) {
            int r = sum( requests[ i ].r ) - sum( requests[ i ].l - 1 );
            ans[ requests[ i ].idx ] = ( requests[ i ].r - requests[ i ].l + 1 ) - r;
        }
        else {
            add( requests[ i ].idx );
        }
    }
    for ( i = 0; i < Q; ++i ) {
        printf( "%d\n", ans[ i ] );
    }
    return 0;
}
