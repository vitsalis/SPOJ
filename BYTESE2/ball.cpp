#include <cstdio>

using namespace std;

int main() {
    int t, i, N, en, exi, m, count, min, max;
    bool birth[ 1000001 ], death[ 1000001 ];
    scanf( "%d", &t );
    for ( i = 0; i <= 1000000; ++i ) {
        birth[ i ] = death[ i ] = false;
    }
    while ( t-- ) {
        scanf( "%d", &N );
        min = 10000000;
        max = 0;
        for ( i = 0; i < N; ++i ) {
            scanf( "%d%d", &en, &exi );
            birth[ en ] = true;
            death[ exi ] = true;
            if ( en < min ) {
                min = en;
            }
            if ( exi > max ) {
                max = exi;
            }
        }
        m = count = 0;
        for ( i = min; i <= max; ++i ) {
            if ( birth[ i ] ) {
                ++count;
                birth[ i ] = false;
            }
            if ( death[ i ] ) {
                --count;
                death[ i ] = false;
            }
            if ( count > m ) {
                m = count;
            }
        }
        printf( "%d\n", m );
    }
    return 0;
}
