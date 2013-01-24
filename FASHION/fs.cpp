#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long int sum = 0;
	int t, N, men[ 1000 ], women[ 1000 ], i;

	scanf( "%d", &t );
	while ( t > 0 ) {
		scanf( "%d", &N );
		for ( i = 0; i < N; ++i ) {
			scanf( "%d", men + i );
		}
		for ( i = 0; i < N; ++i ) {
			scanf( "%d", women + i );
		}
		sort( men, men + N );
		sort( women, women + N );
		for ( i = 0; i < N; ++i ) {
			sum = sum + ( men[ i ] * women[ i ] );
		}
		printf( "%lld\n", sum );
		sum = 0;
		--t;
	}

	return 0;
}
