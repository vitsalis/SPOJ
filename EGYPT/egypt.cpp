#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int array[ 3 ];

	while ( 1 ) {
		scanf( "%d%d%d", array, array + 1, array + 2 );
		if ( array[ 0 ] == 0 && array[ 1 ] == 0 && array[ 2 ] == 0 ) break;
		sort( array, array + 3 );
		if ( pow( array[ 0 ], 2 ) + pow( array[ 1 ], 2 ) == pow( array[ 2 ], 2 ) ) {
			printf( "right\n" );
		}
		else {
			printf( "wrong\n" );
		}
	}
	return 0;
}
