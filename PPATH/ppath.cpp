#include <cstdio>
#include <queue>

using namespace std;

int P[ 10000 ];

void fun( queue< int > &q, bool prime[], int dist[], bool visited[], int num, int add ) {
    int k = num;
    int m = add * 10;
    while ( ( k - add ) / 1000 > 0 && ( k % m ) / add > 0 ) {
        k -= add;
        if ( prime[ k ] && !visited[ k ] ) {
            q.push( k );
            dist[ k ] = dist[ num ] + 1;
            P[ k ] = num;
            visited[ k ] = true;
        }
    }
    k = num;
    while ( ( k + add ) / 1000 > 0 && ( k % m ) / add  < 9 ) {
        k += add;
        if ( prime[ k ] && !visited[ k ] ) {
            q.push( k );
            visited[ k ] = true;
            dist[ k ] = dist[ num ] + 1;
            P[ k ] = num;
        }
    }
}

void printPath( int p ) {
    if ( P[ p ] != -1 ) {
        printPath( P[ p ] );
    }
    printf( "%d\n", p );
}

void bfs( bool prime[], int S, int T ) {
    bool visited[ 10000 ];
    int dist[ 10000 ];
    int i, p, k;
    for ( i = 0; i < 10000; ++i ) {
        visited[ i ] = false;
    }
    queue< int > q;
    q.push( S );
    dist[ S ] = 0;
    P[ S ] = -1;
    while ( !q.empty() ) {
        p = q.front();
        q.pop();
        visited[ p ] = true;
        if ( p == T ) {
            printf( "%d\n", dist[ p ] );
            return;
        }
        fun( q, prime, dist, visited, p, 1 );
        fun( q, prime, dist, visited, p, 10 );
        fun( q, prime, dist, visited, p, 100 );
        fun( q, prime, dist, visited, p, 1000 );
    }
    printf( "Impossible\n" );
}

int main() {
    bool prime[ 10000 ];
    int t, i, j, u, v;
    for ( i = 0; i < 10000; ++i ) {
        prime[ i ] = true;
    }
    for ( i = 2; i < 10000; ++i ) {
        for ( j = 2 * i; j < 10000; j += i ) {
            prime[ j ] = false;
        }
    }
    scanf( "%d", &t );
    while ( t ) {
        scanf( "%d%d", &u, &v );
        bfs( prime, u, v );
        --t;
    }
    return 0;
}
