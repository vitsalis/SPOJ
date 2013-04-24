#include <cstdio>
#include <algorithm>
#define MAX 10000 

using namespace std;

struct bridge {
    int b, e;
};

bool operator <( bridge a, bridge b ) {
    if ( a.b == b.b ) {
        return a.e < b.e;
    }
    return a.b < b.b;
}

long long int bit[ MAX + 1 ];
int maxval;

long long int sum( int y ) {
    long long int res = 0;
    while ( y > 0 ) {
        res += bit[ y ];
        y -= ( y & -y );
    }
    return res;
}

void add( int y, int val ) {
    while ( y <= maxval ) {
        bit[ y ] += val;
        y += ( y & -y );
    }
}

int main() {
    int t, T, i, M, K, N;
    long long int s;
    bridge array[ 1000000 ];
    scanf( "%d", &T );
    for ( t = 1; t <= T; ++t ) {
        scanf( "%d%d%d", &N, &M, &K );
        maxval = M;
        for ( i = 0; i <= M; ++i ) {
            bit[ i ] = 0;
        }
        for ( i = 0; i < K; ++i ) {
            scanf( "%d%d", &array[ i ].b, &array[ i ].e );
        }
        sort( array, array + K );
        s = 0;
        for ( i = 0; i < K; ++i ) {
            add( array[ i ].e, 1 );
            s += sum( M ) - sum( array[ i ].e );
        }
        printf( "Test case %d: %lld\n", t, s );
    }
    return 0;
}
