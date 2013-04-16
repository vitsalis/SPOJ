#include <cstdio>
#define MAX 100000

using namespace std;

int tree[ 4 * MAX + 1 ];
bool flag[ 4 * MAX + 1 ];

void init( int node, int i, int j ) {
    if ( i == j ) {
        tree[ node ] = 0;
        flag[ node ] = false;
    }
    else {
        init( node * 2, i, ( i + j ) / 2 );
        init( node * 2 + 1, ( i + j ) / 2 + 1, j );
        tree[ node ] = 0;
        flag[ node ] = false;
    }
}

void refresh( int node, int a, int b ) {
    if ( flag[ node ] ) {
        flag[ node ] = false;
        tree[ node ] = b - a + 1 - tree[ node ];
        if ( a != b ) {
            flag[ node * 2 ] = !flag[ node * 2 ];
            flag[ node * 2 + 1 ] = !flag[ node * 2 + 1 ];
        }
    }
}

void update( int node, int a, int b, int i, int j ) { 
    if ( a > b || a > j || b < i ) {
        refresh( node, a, b );
        return;
    }
    if ( a >= i && b <= j ) {
        flag[ node ] = !flag[ node ];
        refresh( node, a, b );
        return;
    }
    refresh( node, a, b );
    update( node * 2, a, ( a + b ) / 2, i, j );
    update( node * 2 + 1, ( a + b ) / 2 + 1, b, i, j );
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
    int N, M, i, op, l, r;
    scanf( "%d%d", &N, &M );
    init( 1, 0, N - 1 );
    for ( i = 0; i < M; ++i ) {
        scanf( "%d%d%d", &op, &l, &r );
        if ( op == 0 ) {
            update( 1, 0, N - 1, l - 1, r - 1 );
        }
        else {
            printf( "%d\n", query( 1, 0, N - 1, l - 1, r - 1 ) );
        }
    }
    return 0;
}
