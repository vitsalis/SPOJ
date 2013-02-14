#include <cstdio>
#include <algorithm>

using namespace std;

int max( long long int a, long long int b ) { return ( a > b )? a : b; }

long long int knapSack( int S, int N, long long int wei[], long long int val[] ) {
	int i, w;
	long int K[ N + 1 ][ S + 1 ];

	for ( i = 0; i <= N; ++i ) {
		for ( w = 0; w <= S; ++w ) {
			if ( i == 0 || w == 0 ) {
				K[ i ][ w ] = 0;
			}
			else if ( wei[ i - 1 ] <= w ) {
				K[ i ][ w ] = max( val[ i - 1 ] + K[ i - 1 ][ w - wei[ i - 1 ] ], K[ i - 1 ][ w ] );
			}
			else {
				K[ i ][ w ] = K[ i - 1 ][ w ];
			}
		}
	}
	return K[ N ][ S ];
}

int main() {
	int S, N, i;
	scanf( "%d%d", &S, &N );
	long long int wei[ N + 1 ], val[ N + 1 ];
	for ( i = 0; i < N; ++i ) {
		scanf( "%lld%lld", wei + i, val + i );
	}

	printf( "%lld\n", knapSack( S, N, wei, val ) );
	
	return 0;
}
