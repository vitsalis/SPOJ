#include <cstdio>
#include <string>
#include <cctype>

using namespace std;

bool machu( string a ) {
	int i;
	char c;
	for ( i = 0; i < a.length(); ++i ) {
		c = a[ i ];
		if ( isalpha( c ) ) return true;
	}
	return false;
}

void printString( string a ) {
	int i;
	for ( i = 0; i < a.length(); ++i ) {
		printf( "%c", a[ i ] );
	}
}

int decode( string a ) {
	int i, num = a[ 0 ] - '0';
	for ( i = 1; i < a.length(); ++i ) {
		num = ( num * 10 ) + ( a[ i ] - '0' );
	}
	return num;
}

int main() {
	int t;
	int i, j;
	bool found;
	scanf( "%d", &t );
	string a, b, c;
	char s[ 1000 ];
	for ( j = 0; j < t; ++j ) {
		scanf( "%s", s );
		a = s;
		scanf( "%*s", s );
		scanf( "%s%*s", s );
		b = s;
		scanf( "%s", s );
		c = s;
		if ( machu( a ) ) {
			printf( "%d ", decode( c ) - decode( b ) );
			printf( "+ " );
			printString( b );
			printf( " = " );
			printString( c );
			printf( "\n" );
		}
		else if ( machu( b ) ) {
			printString( a );
			printf( " + %d = ", decode( c ) - decode( a ) );
			printString( c );
			printf( "\n" );
		}
		else {
			printString( a );
			printf( " + " );
			printString( b );
			printf( " = %d\n", decode( a ) + decode( b ) );
		}
	}
	return 0;
}
