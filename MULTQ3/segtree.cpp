#include <cstdio>
#define MAX 100000

using namespace std;

struct triple {
    int one, two, three;
};

struct tf {
    triple val;
    int flag;
};

tf tree[ 4 * MAX + 1 ];

void init( int node, int i, int j ) {
    if ( i == j ) {
        tree[ node ] = ( ( tf ) { ( ( triple ) { 0, 0, 1 } ), 0 } );
    }
    else {
        init( node * 2, i, ( i + j ) / 2 );
        init( node * 2 + 1, ( i + j ) / 2 + 1, j );
        tree[ node ] = ( ( tf ) { ( ( triple ) { 0, 0, j - i + 1 } ), 0 } );
    }
}

void rotate( int node ) {
    int temp = tree[ node ].val.one;
    tree[ node ].val.one = tree[ node ].val.three;
    tree[ node ].val.three = tree[ node ].val.two;
    tree[ node ].val.two = temp;
}

void refresh( int node, int a, int b ) {
    if ( tree[ node ].flag ) {
        tree[ node ].flag %= 3;
        if ( a != b ) {
            tree[ node * 2 ].flag += tree[ node ].flag;
            tree[ node * 2 + 1 ].flag += tree[ node ].flag;
        }
        while ( tree[ node ].flag > 0 ) {
            tree[ node ].flag = tree[ node ].flag - 1;
            rotate( node );
        }
    }
}

void update( int node, int a, int b, int i, int j ) {
    if ( a > j || b < i || a > b ) {
        refresh( node, a, b );
        return;
    }
    if ( a >= i && b <= j && a <= b ) {
        tree[ node ].flag += 1;
        refresh( node, a, b );
        return;
    }
    refresh( node, a, b );
    update( node * 2, a, ( a + b ) / 2, i, j );
    update( node * 2 + 1, ( a + b ) / 2 + 1, b, i, j );
    if ( a != b ) {
        triple left = tree[ node * 2 ].val, right = tree[ node * 2 + 1 ].val;
        tree[ node ].val.one = left.one + right.one;
        tree[ node ].val.two = left.two + right.two;
        tree[ node ].val.three = left.three + right.three;
    }
}

int query( int node, int a, int b, int i, int j ) {
    refresh( node, a, b );
    if ( a == i && b == j ) {
        return tree[ node ].val.three;
    }
    if ( j <= ( a + b ) / 2 ) {
        return query( node * 2, a, ( a + b ) / 2, i, j );
    }
    if ( i > ( a + b ) / 2 ) {
        return query( node * 2 + 1, ( a + b ) / 2 + 1, b, i, j );
    }
    return query( node * 2, a, ( a + b ) / 2, i, ( a + b ) / 2 ) + query( node * 2 + 1, ( a + b ) / 2 + 1, b, ( a + b ) / 2 + 1, j );
}

int readint() {
    int n = 0;
    char c = getchar_unlocked();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

int main() {
    int N, t, i, op, l, r;
    N = readint();
    t = readint();
    init( 1, 0, N - 1 );
    while ( t-- ) {
        op = readint();
        l = readint();
        r = readint();
        if ( op == 1 ) {
            printf( "%d\n", query( 1, 0, N - 1, l, r ) );
        }
        else {
            update( 1, 0, N - 1, l, r );
        }
    }
    return 0;
}
