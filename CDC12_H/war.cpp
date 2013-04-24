#include <cstdio>
#include <cstring>
#define MAX 150000

using namespace std;

long long tree[ 4 * MAX + 1 ], flag[ 4 * MAX + 1 ];

void init( int node, int i, int j ) {
    if ( i == j ) {
        tree[ node ] = 0;
        flag[ node ] = 0;
    }
    else {
        init( node * 2, i, ( i + j ) / 2 );
        init( node * 2 + 1, ( i + j ) / 2 + 1, j );
        tree[ node ] = 0;
        flag[ node ] = 0;
    }
}

void refresh( int node, int a, int b ) {
    if ( flag[ node ] ) {
        tree[ node ] += ( b - a + 1 ) * flag[ node ];
        if ( a != b ) {
            flag[ node * 2 ] += flag[ node ];
            flag[ node * 2 + 1 ] += flag[ node ];
        }
        flag[ node ] = 0;
    }
}

void update( int node, int a, int b, int i, int j ) {
    if ( a > b || a > j || b < i ) {
        refresh( node, a, b );
        return;
    }
    if ( a >= i && b <= j ) {
        flag[ node ] += 1;
        refresh( node, a, b );
        return;
    }
    refresh( node, a, b );
    update( node * 2, a, ( a + b ) / 2, i, j );
    update( node * 2 + 1, ( a + b ) / 2 + 1, b, i, j );
    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
}

long long int query( int node, int a, int b, int i, int j ) {
    if ( a > b || a > j || b < i ) {
        return 0;
    }
    refresh( node, a, b );
    if ( a >= i && b <= j ) {
        return tree[ node ];
    }
    const int mid = ( a + b ) / 2;
    return query( node * 2, a, mid, i, j ) + query( node * 2 + 1, mid + 1, b, i, j );
}

int main() {
    int t, N, Q, i, k, l, r;
    char ans[ 10 ] = "answer", s[ 20 ];
    scanf( "%d", &t );
    for ( k = 1; k <= t; ++k ) {
        printf( "Scenario #%d:\n", k );
        scanf( "%d%d", &N, &Q );
        init( 1, 0, N - 1 );
        for ( i = 0; i < Q; ++i ) {
            scanf( "%s%d%d", s, &l, &r );
            if ( strcmp( ans, s ) == 0 ) {
                printf( "%lld\n", query( 1, 0, N - 1, l - 1, r - 1 ) );
            }
            else {
                printf( "OK\n" );
                update( 1, 0, N - 1, l - 1, r - 1 );
            }
        }
    }
    return 0;
}
