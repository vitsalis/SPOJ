#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t, j = 1, array[ 1000 ], num = 0, pe, ned, i, sum;
	bool found = false;
	scanf( "%d", &t );

	while ( j <= t ) {
		scanf( "%d%d", &ned, &pe );
		for ( i = 0; i < pe; ++i ) {
			scanf( "%d", array + i );
		}
		sort( array, array + pe );
		sum = 0;
		num = 0;
		for ( i = pe - 1; i >= 0; --i ) {
			sum += array[ i ];
			++num;
			if ( sum >= ned ) {
				found = true;
				break;
			}
			found = false;
		}

		if ( found ) {
			printf( "Scenario #%d:\n%d\n", j, num );
		}
		else {
			printf( "Scenario #%d:\nimpossible\n", j );
		}
		found = false;
		++j;
	}

	return 0;
}
