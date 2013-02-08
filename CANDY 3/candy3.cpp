#include <cstdio>

using namespace std;

int main() {
	int t, N, i;
	long long int array[ 1000000 ], sum;
	scanf( "%d", &t );
	while ( t > 0 ) {
		scanf( "%d", &N );
		for ( i = 0; i < N; ++i ) {
			scanf( "%lld", array + i );
		}
		sum = 0;
		for ( i = 0; i < N; ++i ) {
			sum = ( sum + array[ i ] ) % N;
		}
		if ( sum == 0 ) {
			printf( "YES\n" );
		}
		else {
			printf( "NO\n" );
		}

		--t;
	}
}
