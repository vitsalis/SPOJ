#include <cstdio>

using namespace std;

#define INF 1000000

bool check( int a, int b, int c ) {
	return a + b < c;
}

int main() {
	int n, m;
	scanf( "%d%d", &n, &m );
	int array[ n ][ m ];
	int dp[ n ][ m ];
	int i, j;
	for ( i = 0; i < n; ++i ) {
		for ( j = 0; j < n; ++j ) {
			scanf( "%d", &array[ i ][ j ] );
			dp[ i ][ j ] = INF;
		}
	}
	for ( i = 0; i < m; ++i ) {
		dp[ 0 ][ i ] = array[ 0 ][ i ];
	}
	for ( i = 0; i < n - 1; ++i ) {
		for ( j = 0; j < m; ++j ) {
			if ( j - 1 >= 0 && check( dp[ i ][ j ], array[ i + 1 ][ j - 1 ], dp[ i + 1 ][ j - 1 ] ) ) {
				dp[ i + 1 ][ j - 1 ] = dp[ i ][ j ] + array[ i + 1 ][ j - 1 ];
			}
			if ( check( dp[ i ][ j ], array[ i + 1 ][ j ], dp[ i + 1 ][ j ] ) ) {
				dp[ i + 1 ][ j ] = dp[ i ][ j ] + array[ i + 1 ][ j ];
			}
			if ( j + 1 < m && check( dp[ i ][ j ], array[ i + 1 ][ j + 1 ], dp[ i + 1 ][ j + 1 ] ) ) {
				dp[ i + 1 ][ j + 1 ] = dp[ i ][ j ] + array[ i + 1 ][ j + 1 ];
			}
		}
	}
	int min = INF;
	for ( i = 0; i < m; ++i ) {
		if ( dp[ n - 1 ][ i ] < min ) {
			min = dp[ n - 1 ][ i ];
		}
	}
	printf( "%d\n", min );
	return 0;
}
