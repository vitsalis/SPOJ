#include <cstdio>

using namespace std;

int main() {
	int N;
	scanf( "%d", &N );
	int i;
	long long int a[ N ], b[ N ];
	long long int max = 0;

	for ( i = 0; i < N; ++i ) {
		scanf( "%lld%lld", a + i, b + i );
		if ( b[ i ] > max ) {
			max = b[ i ];
		}
	}
	bool prime[ max + 1 ];
	for ( i = 0; i <= max; ++i ) {
		prime[ i ] = true;
	}
	for ( i = 2; i <= max; ++i ) {
		for ( int j = 2 * i; j <= max; j += i ) {
			if ( j % i == 0 ) {
				prime[ j ] = false;
			}
		}
	}
	i = 0;
	while ( N > 0 ) {
		for ( int k = a[ i ]; k <= b[ i ]; ++k ) {
			if ( prime[ k ] ) {
				printf( "%d\n", k );
			}
		}
		printf( "\n" );
		++i;
		--N;
	}

	return 0;
}
