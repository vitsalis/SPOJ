#include <cstdio>

#define INF 10000000

using namespace std;

int min( int a, int b ) {
    if ( a > b ) {
        return b;
    }
    return a;
}

int N, D[ 201 ][ 201 ][ 201 ];

void floyd( int mat[][ 201 ] ) {
    int i, j, k;
    for ( k = 0; k <= N; ++k ) {
        for ( i = 1; i <= N; ++i ) {
            for ( j = 1; j <= N; ++j ) {
                if ( k == 0 ) {
                    D[ k ][ i ][ j ] = mat[ i ][ j ];
                }
                else {
                    D[ k ][ i ][ j ] = min( D[ k - 1 ][ i ][ j ], D[ k - 1 ][ i ][ k ] + D[ k - 1 ][ k ][ j ] );
                }
            }
        }
    }
}

int main() {
    int t, mat[ 201 ][ 201 ], i, j, k;
    bool nei[ 201 ][ 201 ], found;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &N );
        for ( i = 1; i <= N; ++i ) {
            for ( j = 1; j <= N; ++j ) {
                scanf( "%d", mat[ i ] + j );
            }
        }
        floyd( mat );
        for ( i = 1; i <= N; ++i ) {
            for ( j = 1; j <= N; ++j ) {
                nei[ i ][ j ] = false;
            }
        }
        for ( i = 1; i <= N; ++i ) {
            for ( j = 1; j <= N; ++j ) {
                found = false;
                for ( k = 1; k <= N; ++k ) {
                    if ( i != k && j != k && D[ N ][ i ][ j ] == D[ N ][ i ][ k ] + D[ N ][ k ][ j ] ) {
                        found = true;
                        break;
                    }
                }
                if ( !found ) {
                    nei[ i ][ j ] = true;
                }
            }
        }
        for ( i = 1; i <= N; ++i ) {
            for ( j = 1; j <= N; ++j ) {
                if ( i != j && nei[ i ][ j ] ) {
                    printf( "%d %d\n", i, j );
                    nei[ j ][ i ] = false;
                }
            }
        }
    }
    return 0;
}
