#include <cstdio>
#include <algorithm>
#define MAX 100000

using namespace std;
long long int tree[ 4 * MAX + 1 ], flag[ 4 * MAX + 1 ];

void init( int node, int a, int b ) {
    if ( a == b ) {
        tree[ node ] = flag[ node ] = 0;
    }
    else {
        init( node * 2, a, ( a + b ) / 2 );
        init( node * 2 + 1, ( a + b ) / 2 + 1, b );
        tree[ node ] = flag[ node ] = 0;
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

void update( int node, int a, int b, int i, int j, int val ) {
    if ( a > b || a > j || b < i ) {
        refresh( node, a, b );
        return;
    }
    if ( a >= i && b <= j ) {
        flag[ node ] += val;
        refresh( node, a, b );
        return;
    }
    refresh( node, a, b );
    update( node * 2, a, ( a + b ) / 2, i, j, val );
    update( node * 2 + 1, ( a + b ) / 2 + 1, b, i, j, val );
    tree[ node ] = tree[ node * 2 ] + tree[ node * 2 + 1 ];
}

long long int query( int node, int a, int b, int i, int j ) {
    if ( a > b || a > j || b < i ) {
        return 0;
    }
    if ( a >= i && b <= j ) {
        refresh( node, a, b );
        return tree[ node ];
    }
    refresh( node, a, b );
    return query( node * 2, a, ( a + b ) / 2, i, j ) + query( node * 2 + 1, ( a + b ) / 2 + 1, b, i, j );
}

int main() {
    int N, M, l, r, val, op, t;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &N, &M );
        init( 1, 0, N - 1 );
        for ( int i = 0; i < M; ++i ) {
            scanf( "%d", &op );
            if ( !op ) {
                scanf( "%d%d%d", &l, &r, &val );
                update( 1, 0, N - 1, l - 1, r - 1, val );
            }
            else {
                scanf( "%d%d", &l, &r );
                printf( "%lld\n", query( 1, 0, N - 1, l - 1, r - 1 ) );
            }
        }
    }
    return 0;
}
