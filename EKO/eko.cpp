#include <cstdio>

using namespace std;

int main() {
    long long int N, i, M;
    scanf( "%lld%lld", &N, &M );
    int array[ N ];
    long long int max = 0, h = 0; 
    long long int beg, end, mid;
    long long int cutted;
    for ( i = 0; i < N; ++i ) {
        scanf( "%d", array + i );
        if ( array[ i ] > max ) {
            max = array[ i ];
        }
    }
    beg = 0;
    end = max;
    while ( beg <= end ) {
        mid = ( beg + end ) / 2;
        cutted = 0;
        for ( i = 0; i < N; ++i ) {
            if ( array[ i ] - mid > 0 ) {
                cutted += array[ i ] - mid;
            }
        }
        if ( cutted > M ) {
            beg = mid + 1;
            if ( mid > h ) {
                h = mid;
            }
        }
        else if ( cutted < M ) {
            end = mid - 1;
        }
        else {
            h = mid;
            break;
        }
    }
    printf( "%lld\n", h );
    return 0;
}
