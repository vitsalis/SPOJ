#include <cstdio>

using namespace std;

int main() {
	int div[ 500001 ];
	int i, j;
	for ( i = 0; i < 500000; ++i ) {
		div[ i ] = 1;
	}
	div[ 2 ] = 1;
	for ( i = 2; i <= 500000; ++i ) {
		for ( j = i + i; j <= 500000; j += i ) {
			if ( j % i == 0 ) {
				div[ j ] += i;
			}
		}
	}
	int t, N;
	scanf( "%d", &t );

	while ( t ) {
		scanf( "%d", &N );
		if ( N == 0 || N == 1 ) {
			printf( "0\n" );
		}
		else {
			printf( "%d\n", div[ N ] );
		}
		--t;
	}
	

	return 0;
}
