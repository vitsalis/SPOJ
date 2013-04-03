#include <cstdio>
#include <algorithm>

#define MAXN 150000 

using namespace std;

struct edge {
    int u;
    int v;
    int w;
};

bool operator <( edge a, edge b ) {
    return a.w < b.w;
}

long long int rank[ MAXN + 1 ], num[ MAXN + 1 ], P[ MAXN + 1 ];

void makeSet( int x ) {
    P[ x ] = x;
    rank[ x ] = 1;
    num[ x ] = 1;
}

int findSet( int x ) {
    if ( x == P[ x ] ) {
        return x;
    }
    else {
        return ( P[ x ] = findSet( P[ x ] ) );
    }
}

void uni( int x, int y ) {
    x = findSet( x );
    y = findSet( y );
    if ( rank[ x ] > rank[ y ] ) {
        P[ y ] = x;
        num[ x ] += num[ y ];
    }
    else {
        P[ x ] = y;
        num[ y ] += num[ x ];
        if ( rank[ x ] == rank[ y ] ) {
            rank[ y ] += 1;
        }
    }
}

int main() {
    int N, i, u, v, t;
    unsigned long long int cost;
    edge array[ MAXN + 1 ];
    scanf( "%d", &t );
    while ( t-- ) {
        cost = 0;
        scanf( "%d", &N );
        for ( i = 0; i < N - 1; ++i ) {
            scanf( "%d%d%d", &array[ i ].u, &array[ i ].v, &array[ i ].w );
            makeSet( array[ i ].u );
            makeSet( array[ i ].v );
        }
        sort( array, array + N - 1 );
        for ( i = 0; i < N - 1; ++i ) {
            u = findSet( array[ i ].u );
            v = findSet( array[ i ].v );
            if ( u != v ) {
                cost += num[ u ] * num[ v ] * ( array[ i ].w + 1 );
                uni( array[ i ].u, array[ i ].v );
            }
        }

        printf( "%lld\n", cost - N + 1 );
    }
    return 0;
}
