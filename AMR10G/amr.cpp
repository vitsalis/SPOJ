#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t, N, i, K, beg; 
    long long int count, m, array[ 20000 ];
    scanf( "%d", &t );
    while ( t > 0 ) {
        scanf( "%d%d", &N, &K );
        for ( i = 0; i < N; ++i ) {
            scanf( "%lld", array + i );
        }
        sort( array, array + N );
        beg = 0;
        count = 1;
        m = 1000000000;
        for ( i = 0; i < N; ++i ) {
            if ( count == K ) {
                --count;
                if ( array[ i ] - array[ beg ] < m ) {
                    m = array[ i ] - array[ beg ];
                }
                ++beg;
            }
            ++count;
        }
        printf( "%lld\n", m );
        --t;
    }
    return 0;
}
