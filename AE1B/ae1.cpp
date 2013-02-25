#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N, tables, ned, i;

    scanf( "%d%d%d", &N, &tables, &ned );
    ned = tables * ned;
    int array[ N ];

    for ( i = 0; i < N; ++i ) {
        scanf( "%d", &array[ i ] );
    }
    sort( array, array + N );
    int count = 0, sum = 0;
    for ( i = N - 1; i >= 0; --i ) {
        if ( sum + array[ i ] >= ned ) {
            printf( "%d\n", count + 1 );
            return 0;
        }
        sum += array[ i ];
        ++count;
    }

    return 0;
}
