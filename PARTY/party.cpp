#include <cstdio>
#include <algorithm>

using namespace std;


void knapsack( int cost[], int fun[], int budg, int N ) {
	int K[ N + 1 ][ budg + 1 ], mon[ N + 1 ][ budg + 1 ];
	int i, j;

	for ( i = 0; i <= N; ++i ) {
		for ( j = 0; j <= budg; ++j ) {
			if ( i == 0 || j == 0 ) {
				K[ i ][ j ] = 0;
				mon[ i ][ j ] = 0;
			}
			else if ( cost[ i - 1 ] <= j ) {
				if ( fun[ i - 1 ] + K[ i - 1 ][ j - cost[ i - 1 ] ] > K[ i - 1 ][ j ] ) {
					K[ i ][ j ] = fun[ i - 1 ] + K[ i - 1 ][ j - cost[ i - 1 ] ];
					mon[ i ][ j ] = cost[ i - 1 ] + mon[ i - 1 ][ j - cost[ i - 1 ] ];
				}
				else {
					K[ i ][ j ] = K[ i - 1 ][ j ];
					mon[ i ][ j ] = mon[ i - 1 ][ j ];
				}
			}
			else {
				K[ i ][ j ] = K[ i - 1 ][ j ];
				mon[ i ][ j ] = mon[ i - 1 ][ j ];
			}
		}
	}
	int m = K[ N ][ budg ];
	int min = 100000000;
	for ( i = 1; i <= budg; ++i ) {
		if ( K[ N ][ i ] == m ) {
			if ( mon[ N ][ i ] < min ) {
				min = mon[ N ][ i ];
			}
		}
	}
	printf( "%d %d\n", min, K[ N ][ budg ] );
}

int main() {
	int cost[ 101 ], fun[ 101 ];
	int budg, N, i;

	while ( 1 ) {
		scanf( "%d%d", &budg, &N );
		if ( budg == 0 && N == 0 ) break;
		for ( i = 0; i < N; ++i ) {
			scanf( "%d %d", cost + i, fun + i );
		}
		if ( budg == 0 || N == 0 ) printf( "0 0\n" );
		else
		knapsack( cost, fun, budg, N );
	}

	return 0;
}
