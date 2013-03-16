#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    scanf( "%d%d", &N, &M );
    int array[ N + 1 ], time[ N + 1 ], i, u, v, count = 0;
    for ( i = 0; i <= N; ++i ) {
        time[ i ] = 0;
    }
    for ( i = 0; i < M; ++i ) {
        scanf( "%d%d", &u, &v );
        time[ u ] += 1;
        time[ v ] -= 1;
    }
    for ( i = 1; i <= N; ++i ) {
        count += time[ i ];
        array[ i ] = count;
    }
    sort( array + 1, array + N );
    printf( "%d\n", array[ N / 2 + 1 ] );
    return 0;
}
