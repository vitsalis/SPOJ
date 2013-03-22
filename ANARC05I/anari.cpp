#include <cstdio>

using namespace std;

int count;

void visit( bool visited[][ 2002 ], int x, int y ) {
    if ( visited[ x ][ y ] ) {
        ++count;
    }
}

int main() {
    char s[ 1001 ];
    bool visited[ 2002 ][ 2002 ];
    int i, j, posx, posy;
    while ( 1 ) {
        scanf( "%s", s );
        if ( s[ 0 ] == 'Q' ) {
            break;
        }
        for ( i = 0; i < 2002; ++i ) {
            for ( j = 0; j < 2002; ++j ) {
                visited[ i ][ j ] = false;
            }
        }
        posx = posy = 1001;
        count = 0;
        for ( i = 0; s[ i ] != 'Q'; ++i ) {
            visited[ posx ][ posy ] = true;
            if ( s[ i ] == 'U' ) {
                visit( visited, posx - 1, posy );
                --posx;
            }
            if ( s[ i ] == 'D' ) {
                visit( visited, posx + 1, posy );
                ++posx;
            }
            if ( s[ i ] == 'L' ) {
                visit( visited, posx, posy - 1 );
                --posy;
            }
            if ( s[ i ] == 'R' ) {
                visit( visited, posx, posy + 1 );
                ++posy;
            }
        }
        printf( "%d\n", count );
    }
    return 0;
}
