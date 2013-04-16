#include <cstdio>
#include <algorithm>
#define MAX 100000

using namespace std;

int array[ MAX + 1 ], tree[ 4 * MAX + 1 ], flag[ 4 * MAX + 1 ];
bool prime[ 2000001 ];

void init( int node, int i, int j ) {
    if ( i == j ) {
        if ( prime[ array[ i ] ] ) {
            tree[ node ] = 1;
        }
        else {
            tree[ node ] = 0;
        }
        flag[ node ] = 0;
    }
    else {
        init( node * 2, i, ( i + j ) / 2 );
        init( node * 2 + 1, ( i + j ) / 2 + 1, j );
        tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
        flag[ node ] = 0;
    }
}

void refresh( int node, int a, int b ) {
    if ( flag[ node ] ) {
        if ( prime[ flag[ node ] ] ) {
            tree[ node ] = b - a + 1;
        }
        else {
            tree[ node ] = 0;
        }
        if ( a != b ) {
            flag[ node * 2 ] = flag[ node ];
            flag[ node * 2 + 1 ] = flag[ node ];
        }
        flag[ node ] = 0;
    }
}

void update( int node, int a, int b, int i, int j, int val ) {
    if ( a > b || a > j || b < i ) {
        refresh( node, a, b );
        return;
    }
    if ( a >= i && b <= j ) {
        flag[ node ] = val;
        refresh( node, a, b );
        return;
    }
    refresh( node, a, b );
    update( node * 2, a, ( a + b ) / 2, i, j, val );
    update( node * 2 + 1, ( a + b ) / 2 + 1, b, i, j, val );
    if ( a != b ) {
        tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
    }
}

int query( int node, int a, int b, int i, int j ) {
    if ( a > b || a > j || b < i ) {
        return 0;
    }
    refresh( node, a, b );
    if ( a >= i && b <= j ) {
        return tree[ node ];
    }
    return query( node * 2, a, ( a + b ) / 2, i, j ) + query( node * 2 + 1, ( a + b ) / 2 + 1, b, i, j );
}

int main() {
    int i, j, t, N, M, op, l, r, val, k;
    for ( i = 0; i <= 1000000; ++i ) {
        prime[ i ] = true;
    }
    for ( i = 2; i <= 1000000; ++i ) {
        for ( j = i * 2; j <= 1000000; j += i ) {
            prime[ j ] = false;
        }
    }
    scanf( "%d", &t );
    for ( k = 1; k <= t; ++k ) {
        scanf( "%d%d", &N, &M );
        for ( i = 0; i < N; ++i ) {
            scanf( "%d", array + i );
        }
        init( 1, 0, N - 1 );
        printf( "Case %d:\n", k );
        for ( i = 0; i < M; ++i ) {
            scanf( "%d", &op );
            if ( !op ) {
                scanf( "%d%d%d", &l, &r, &val );
                update( 1, 0, N - 1, l - 1, r - 1, val );
            }
            else {
                scanf( "%d%d", &l, &r );
                printf( "%d\n", query( 1, 0, N - 1, l - 1, r - 1 ) );
            }
        }
    }
    return 0;
}
