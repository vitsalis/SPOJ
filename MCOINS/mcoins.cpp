#include <cstdio>

using namespace std;

int main() {
    int k, l, n;
    scanf( "%d%d%d", &k, &l, &n );
    int i;
    bool win[ 1000001 ];
    win[ 1 ] = true;
    win[ 0 ] = false;
    for ( i = 2; i <= 1000000; ++i ) {
        if ( !win[ i - 1 ] ) {
            win[ i ] = true;
        }
        else if ( i - k >= 0 && !win[ i - k ] ) {
            win[ i ] = true;
        }
        else if ( i - l >= 0 && !win[ i - l ] ) {
            win[ i ] = true;
        }
        else {
            win[ i ] = false;
        }
    }
    for ( i = 0; i < n; ++i ) {
        scanf( "%d", &k );
        if ( win[ k ] ) {
            printf( "A" );
        }
        else {
            printf( "B" );
        }
    }
    printf( "\n" );
    return 0;
}
