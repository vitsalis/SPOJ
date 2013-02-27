#include <cstdio>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

void init( int dp[][ 2 ], int N ) {
    for ( int i = 0; i <= N; ++i ) {
        dp[ i ][ 0 ] = dp[ i ][ 1 ] = 0;
    }
}

int main() {
    char s[ 10001 ];
    string str;
    int dp[ 10001 ][ 2 ];
    while ( scanf( "%s", s ) != EOF ) {
        str = s;
        init( dp, str.length() );
        dp[ 0 ][ 1 ] = 1;
        for ( int i = 1; i < str.length(); ++i ) {
            if ( isupper( str[ i ] ) == isupper( str[ i - 1 ] ) ) {
                dp[ i ][ 0 ] = dp[ i - 1 ][ 1 ];
                dp[ i ][ 1 ] = dp[ i - 1 ][ 0 ] + 1;
            }
            else {
                dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ];
                dp[ i ][ 1 ] = dp[ i - 1 ][ 1 ] + 1;
            }
        }
        printf( "%d\n", min( dp[ str.length() - 1 ][ 0 ], dp[ str.length() - 1 ][ 1 ] ) );
    }

    return 0;
}
