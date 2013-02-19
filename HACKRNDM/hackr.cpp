#include <cstdio>
#include <algorithm>

using namespace std;

bool bsearch( int array[], int num, int N ) {
	int beg = 0, end = N;

	while ( beg <= end ) {
		int mid = ( beg + end ) / 2;

		if ( array[ mid ] > num ) {
			end = mid - 1;
		}
		else if ( array[ mid ] < num ) {
			beg = mid + 1;
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	int n, k;
	scanf( "%d%d", &n, &k );
	int array[ n ], i, count = 0;

	for ( i = 0; i < n; ++i ) {
		scanf( "%d", array + i );
	}

	sort( array, array + n );

	for ( i = 0; i < n; ++i ) {
		if ( bsearch( array, array[ i ] + k, n ) ) {
			++count;
		}
	}

	printf( "%d\n", count );
	return 0;
}
