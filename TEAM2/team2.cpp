#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long int array[ 4 ], num;
	int i, j = 0;
	while ( scanf( "%lld", &num ) != EOF ) {
		++j;
		array[ 0 ] = num;
		for ( i = 1; i <= 3; ++i ) {
			scanf( "%lld", array + i );
		}
		sort( array, array + 4 );
		printf( "Case %d: %lld\n", j, array[ 2 ] + array[ 3 ]  );
	}

	return 0;
}
