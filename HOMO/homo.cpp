#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main() {
    int i, N, hom, het, v;
    map< int, int > mymap;
    char s[ 100000 ];
    char ins[ 15 ] = "insert", del[ 15 ] = "delete";
    scanf( "%d", &N );
    hom = het = 0;
    for ( i = 0; i < N; ++i ) {
        scanf( "%s%d", s, &v );
        if ( strcmp( s, ins ) == 0 ) {
            mymap[ v ] += 1;
            if ( mymap[ v ] == 2 ) {
                ++hom;
            }
            else if ( mymap[ v ] == 1 ) {
                ++het;
            }
        }
        else {
            if ( mymap[ v ] > 0 ) {
                mymap[ v ] -= 1;
                if ( mymap[ v ] == 1 ) {
                    --hom;
                }
                else if ( mymap[ v ] == 0 ) {
                    --het;
                }
            }
        }
        if ( hom >= 1 && het >= 2 ) {
            printf( "both\n" );
        }
        else if ( hom >= 1 ) {
            printf( "homo\n" );
        }
        else if ( het >= 2 ) {
            printf( "hetero\n" );
        }
        else {
            printf( "neither\n" );
        }
    }
    return 0;
}
