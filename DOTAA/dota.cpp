#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int test, N, T, D, array[ 501 ], i;
	scanf( "%d", &test );

	while ( test ) {
		scanf( "%d%d%d", &N, &T, &D );
		for ( i = 0; i < N; ++i ) {
			scanf( "%d", array + i );
		}
		sort( array, array + N );
		i = N - 1;
		while ( i >= 0 ) {
			if ( array[ i ] > D ) {
				array[ i ] -= D;
				--T;
			}
			else if ( array[ i ] <= D ) {
				--i;
			}
			if ( T == 0 ) {
				break;
			}
		}
		if ( T == 0 ) {
			printf( "YES\n" );
		}
		else {
			printf( "NO\n" );
		}
		--test;
	}

	return 0;
}
