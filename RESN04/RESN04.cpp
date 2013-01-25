#include <cstdio>

using namespace std;

int main() {
	int t, N, array[ 101 ], i, found = 0, count = 1;
	scanf( "%d", &t );

	while ( t ) {
		scanf( "%d", &N );
		for ( i = 0; i < N; ++i ) {
			scanf( "%d", array + i );
		}
		while ( 1 ) {
			for ( i = 0; i < N; ++i ) {
				if ( array[ i ] - ( i + 1 ) >= 0 ) {
					array[ i ] -= i + 1;
					found = 1;
					break;
				}
				found = 0;
			}
			if ( !found ) {
				if ( count % 2 == 0 ) {
					printf( "ALICE\n" );
					break;
				}
				else {
					printf( "BOB\n" );
					break;
				}
			}
			found = 0;
			++count;
		}
		count = 1;
		found = 0;
		--t;
	}

	return 0;
}
