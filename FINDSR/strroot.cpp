#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int div[ 1000000 ];

int findDiv( int num ) {
	int i, j = 0;

	for ( i = 1; i <= num / 2; ++i ) {
		if ( num % i == 0 ) {
			div[ j++ ] = i;
		}
	}
	div[ j ] = num;
	return j;
}

bool check( int end, string str ) {
	char a[ end + 1 ], b[ end + 1 ];
	int i, j;

	for ( i = 0; i < end; ++i ) {
		a[ i ] = str[ i ];
	}
	a[ end ] = '\0';
	j = 0;
	while ( i < str.length() ) {
		while ( j < end ) {
			b[ j++ ] = str[ i++ ];
		}
		b[ end ] = '\0';
		j = 0;
		if ( strcmp( a, b ) != 0 ) return false;
	}
	return true;
}

int main() {
	int N, i;
	string str;
	char s[ 1000000 ];

	while ( 1 ) {
		scanf( "%s", s );
		str = s;
		if ( str.length() == 1 && str[ 0 ] == '*' ) break;

		N = findDiv( str.length() );
		for ( i = 0; i <= N; ++i ) {
			if ( check( div[ i ], str ) ) {
				printf( "%d\n", str.length() / div[ i ] );
				break;
			}
		}
		s[ 0 ] = '\0';
	}
	return 0;

	return 0;
}
