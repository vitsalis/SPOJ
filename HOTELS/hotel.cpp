#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, cost;
	scanf( "%d%d", &N, &cost );
	int array[ N ], max[ N ];
	int point = 0, i;

	for ( i = 0; i < N; ++i ) {
		scanf( "%d", array + i );
		max[ i ] = 0;
	}
	int currcost = 0;
	for ( i = 0; point < N && i < N; ) {
		currcost += array[ i ];
		if ( max[ point ] + array[ i ] > cost ) {
			currcost = currcost - array[ point ] - array[ i ];
			++point;
			max[ point ] = currcost;
		}
		else {
			max[ point ] += array[ i ];
			++i;
		}
	}
	sort( max, max + N );
	printf( "%d\n", max[ N - 1 ] );
}
