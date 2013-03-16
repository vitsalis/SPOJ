#include <cstdio>
#include <cmath>

#define MAX 20000 
using namespace std;

int rank[ MAX + 1 ], P[ MAX + 1 ], sol[ MAX + 1 ];

void makeNode( int x ) {
    rank[ x ] = 1;
    P[ x ] = x;
    sol[ x ] = 0;
}

int findSet( int x ) {
    if ( x != P[ x ] ) {
        int i = P[ x ];
        P[ x ] = findSet( P[ x ] );
        sol[ x ] += sol[ i ];
    }
    return P[ x ];
}

void Union( int x, int y ) {
    P[ x ] = y;
    sol[ x ] = ( int )fabs( x - y ) % 1000;
}

int main() {
    int t, N, i, u, v;
    char c;
    scanf( "%d", &t );
    while ( t ) {
        scanf( "%d", &N );
        for ( i = 1; i <= N; ++i ) {
            makeNode( i );
        }
        while ( 1 ) {
            scanf( "%*c%c", &c );
            if ( c == 'O' ) {
                break;
            }
            if ( c == 'E' ) {
                scanf( "%d", &u );
                findSet( u );
                printf( "%d\n", sol[ u ] );
            }
            if ( c == 'I' ) {
                scanf( "%d%d", &u, &v );
                if ( findSet( u ) != findSet( v ) ) {
                    Union( u, v );
                }
            }
        }
        --t;
    }
    return 0;
}
