#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int A, D, atac[ 11 ], def[ 11 ];

	while ( 1 ) {
		scanf( "%d%d", &A, &D );
		if ( A == 0 && D == 0 ) {
			break;
		}
		int i, j;
		for ( i = 0; i < A; ++i ) {
			scanf( "%d", atac + i );
		}
		for ( i = 0; i < D; ++i ) {
			scanf( "%d", def + i );
		}
		sort( def, def + D );

		for ( i = 0; i < A; ++i ) {
			if ( atac[ i ] < def[ 1 ] ) {
				printf( "Y\n" );
				break;
			}
		}
		if ( i == A ) {
			printf( "N\n" );
		}
	}

	return 0;
}
