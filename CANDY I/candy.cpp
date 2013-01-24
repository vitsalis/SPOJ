#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, i, j, sum, array[ 10000 ], count;

	while ( 1 ) {
		scanf( "%d", &N );
		sum = 0;
		if ( N == -1 ) {
			break;
		}
		for ( i = 0; i < N; ++i ) {
			scanf( "%d", array + i );
			sum += array[ i ];
		}
		if ( sum % N != 0 ) {
			printf( "-1\n" );
		}
		else {
			sort( array, array + N );
			count = 0;
			for ( i = N - 1; i > 0; --i ) {
				for ( j = 0; array[ i ] > sum / N; ++j ) {
					while ( array[ j ] < sum / N && array[ i ] > sum / N ) {
						array[ j ] += 1;
						array[ i ] -= 1;
						++count;
					}
				}
			}
			printf( "%d\n", count );
		}
	}
	return 0;
}
