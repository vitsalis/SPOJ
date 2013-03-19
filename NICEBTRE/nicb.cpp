#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

long long int m;
int dist[ 100000 ];

int dfs( char* s, int S ) {
    if ( s[ S ] == 'l' ) {
        return S + 1;
    }
    dist[ S + 1 ] = dist[ S ] + 1;
    int pos = dfs( s, S + 1 );
    dist[ pos ] = dist[ S ] + 1;
    return ( dfs( s, pos ) );
}

int main() {
    int i, t;
    char s[ 100001 ];
    scanf( "%d", &t );
    while ( t ) {
        scanf( "%s", s );
        dist[ 0 ] = 0;
        dfs( s, 0 );
        m = 0;
        for ( i = 0; s[ i ] != '\0'; ++i ) {
            if ( dist[ i ] > m ) {
                m = dist[ i ];
            }
            dist[ i ] = 0;
        }
        printf( "%lld\n", m );
        --t;
    }
    return 0;
}
