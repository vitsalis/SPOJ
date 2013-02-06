#include <cstdio>
#include <string>
#include <cctype>

using namespace std;

int check( string lang ) {
	int i;
	if ( isupper( lang[ 0 ] ) || lang[ 0 ] == '_' || lang[ lang.length() -1 ] == '_' ) {
		return -1;
	}
	bool java = false, c = false;
	for ( i = 0; i < lang.length(); ++i ) {
		if ( isupper( lang[ i ] ) ) {
			if ( c ) {
				return -1;
			}
			java = true;
		}
		else if ( lang[ i ] == '_' ) {
			if ( i + 1 < lang.length() && lang[ i + 1 ] == '_' ) {
				return -1;
			}
			if ( java ) {
				return -1;
			}
			c = true;
		}
	}
	return java;
}

void toJava( string lang ) {
	int i;
	for ( i = 0; i < lang.length(); ++i ) {
		if ( lang[ i ] == '_' ) {
			printf( "%c", toupper( lang[ i + 1 ] ) );
			++i;
		}
		else {
			printf( "%c", lang[ i ] );
		}
	}
	printf( "\n" );
}

void toC( string lang ) {
	int i;
	for ( i = 0; i < lang.length(); ++i ) {
		if ( isupper( lang[ i ] ) ) {
			printf( "_%c", tolower( lang[ i ] ) );
		}
		else {
			printf( "%c", lang[ i ] );
		}
	}
	printf( "\n" );
}

int main() {
	string lang;
	char s[ 101 ];

	while ( scanf( "%s", s ) != EOF ) {
		lang = s;
		int n = check( lang );
		if ( n == 0 ) {
			toJava( lang );
		}
		else if ( n == 1 ) {
			toC( lang );
		}
		else {
			printf( "Error!\n" );
		}
	}
}
