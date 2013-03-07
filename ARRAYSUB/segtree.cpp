#include <cstdio>
#include <algorithm>

#define MAX 100000

using namespace std;

int* segtree;

void init( int i, int l, int r, int A[] ) {
    if ( l == r ) {
        segtree[ i ] = A[ l ];
    }
    else {
        init( 2 * i, l, ( l + r ) / 2, A ); 
        init( 2 * i + 1, ( l + r ) / 2 + 1, r, A );
        segtree[ i ] = max( segtree[ i * 2 ], segtree[ i * 2 + 1 ] );
    }
}

int query( int N, int l, int r, int i, int j ) {
    if ( l > j || r < i ) {
        return 0;
    }
    else if ( i <= l && r <= j ) {
        return segtree[ N ];
    }
    else {
        return max( query( 2 * N, l, ( l + r ) / 2, i, j ), query( 2 * N + 1, ( l + r ) / 2 + 1, r, i, j ) );
    }
}

int main() {
    int N;
    scanf( "%d", &N );
    int array[ N + 1 ];
    segtree = new int[ 4 * ( N + 1 ) ];
    int i;
    for ( i = 1; i <= N; ++i ) {
        scanf( "%d", array + i );
    }
    init( 1, 1, N, array );
    int k;
    scanf( "%d", &k );
    for ( i = 1; i + k - 1 <= N; ++i ) {
        printf( "%d ", query( 1, 1, N, i, i + k - 1 ) );
    }
    printf( "\n" );
    return 0;
}
