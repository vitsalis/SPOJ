#include <cstdio>

using namespace std;

int main() {
	char string[ 10000 ];
	char s[ 1000 ][ 21 ];
	int N, i, j, count = 0, ans = 1;
	while ( 1 ) {
		scanf( "%d", &N );
		if ( N == 0 ) {
			break;
		}
		scanf( "%s", string );

		for ( i = 0; string[ i ] != '\0'; ++i ) {
			if ( ans % 2 == 0 ) {
				for ( j = N - 1; j >= 0; --j, ++i ) {
					s[ count ][ j ] = string[ i ];
				}
			}
			else {
				for ( j = 0; j < N; ++j, ++i ) {
					s[ count ][ j ] = string[ i ];
				}
			}
			--i;
			++count;
			++ans;
		}
		for ( i = 0; i < N; ++i ) {
			for ( j = 0; j < count; ++j ) {
				printf( "%c", s[ j ][ i ] );
			}
		}
		printf( "\n" );
		count = 0;
		ans = 1;
	}
}
