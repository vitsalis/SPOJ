#include <cstdio>
#include <string>

using namespace std;

int main() {
    int t, i, j, k = 0, beg;
    bool found = true;
    string str;
    char s[ 100 ];
    char n[ 100 ], c[ 100 ];
    scanf( "%d", &t );

    while ( t > 0 ) {
        scanf( "%s", s );
        str = s;
        for ( i = 0; i < str.length(); ++i ) {
            beg = 0;
            for ( j = i; j < str.length(); ++j ) {
               n[ beg++ ] = str[ j ]; 
               for ( k = 0; k < beg; ++k ) { 
                    c[ k ] = n[ beg - k - 1 ];
               }
               c[ k ] = '\0';
               if ( str.find( c, 0, beg ) == std::string::npos ) {
                    found = false;
               }
            }  
        }
        if ( found ) {
            printf( "YES\n" );
        }
        else {
            printf( "NO\n" );
        }
        found = true;
        --t;
    }
    return 0;
}
