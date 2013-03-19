#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs( vector< int > graph[], bool visited[], int fwei[], int wei[], int val[], int &pos, int S ) {
    queue< int > q;
    q.push( S );
    int w, count, p, i, k;
    w = count = 0;
    visited[ S ] = true;
    while ( !q.empty() ) {
        p = q.front();
        q.pop();
        w += fwei[ p ];
        ++count;
        visited[ p ] = true;
        for ( i = 0; i < graph[ p ].size(); ++i ) {
            k = graph[ p ][ i ];
            if ( !visited[ k ] ) {
                visited[ k ] = true;
                q.push( k );
            }
        }
    }
    wei[ pos ] = w;
    val[ pos ] = count;
    ++pos;
}

void knapSack( int wei[], int val[], int W, int N ) {
    long int K[ N + 1 ][ W + 1 ];
    int i, j;
    for ( i = 0; i <= N; ++i ) {
        for ( j = 0; j <= W; ++j ) {
            if ( i == 0 || j == 0 ) {
                K[ i ][ j ] = 0;
            }
            else if ( j >= wei[ i ] ) {
                K[ i ][ j ] = max( val[ i ] + K[ i - 1 ][ j - wei[ i ] ], K[ i - 1 ][ j ] );
            }
            else {
                K[ i ][ j ] = K[ i - 1 ][ j ];
            }
        }
    }
    printf( "%ld\n", K[ N ][ W ] );
}

int main() {
    int N, W, i, j, lim, v, k;
    int fwei[ 1001 ], wei[ 1001 ], val[ 1001 ];
    bool visited[ 1001 ];
    vector< int > graph[ 1001 ];
    while ( 1 ) {
        scanf( "%d%d", &N, &W );
        if ( N == 0 && W == 0 ) {
            break;
        }
        for ( i = 1; i <= N; ++i ) {
            scanf( "%d", fwei + i );
            visited[ i ] = false;
        }
        for ( i = 1; i <= N; ++i ) {
            scanf( "%d", &lim );
            for ( j = 0; j < lim; ++j ) {
                scanf( "%d", &v );
                graph[ i ].push_back( v );
                graph[ v ].push_back( i );
            }
        }
        k = 1;
        for ( i = 1; i <= N; ++i ) {
            if ( !visited[ i ] ) {
                dfs( graph, visited, fwei, wei, val, k, i );
            }
        }
        knapSack( wei, val, W, k + 1 );
        for ( i = 1; i <= N; ++i ) {
            graph[ i ].clear();
            wei[ i ] = 0;
            val[ i ] = 0;
        }
    }
    return 0;
}
