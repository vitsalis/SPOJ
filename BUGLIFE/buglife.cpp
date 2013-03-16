#include <cstdio>
#include <queue>
#include <vector>

#define MAX 2000 

using namespace std;

int colour[ MAX + 1 ], j;
bool found;

void bfs( int S, vector< int > graph[], int N, bool *visited ) {
    int i, p, k;
    queue< int > q;
    q.push( S );
    colour[ S ] = 0;
    while ( !q.empty() ) {
        p = q.front();
        q.pop();
        visited[ p ] = true;
        for ( i = 0; i < graph[ p ].size(); ++i ) {
            k = graph[ p ][ i ];
            if ( colour[ k ] == colour[ p ] ) {
                found = true;
                return;
            }
            if ( colour[ p ] == 1 ) {
                colour[ k ] = 0;
            }
            else {
                colour[ k ] = 1;
            }
            if ( !visited[ k ] ) {
                q.push( k );
            }
        }
    }
}

int main() {
    int t, N, M, u, v, i;
    vector< int > graph[ MAX + 1 ];
    bool visited[ MAX + 1 ];
    scanf( "%d", &t );
    for ( j = 1; j <= t; ++j ) {
        scanf( "%d%d", &N, &M );
        for ( i = 1; i <= N; ++i ) {
            colour[ i ] = -1;
            visited[ i ] = false;
            graph[ i ].clear();
        }
        found = false;
        for ( i = 0; i < M; ++i ) {
            scanf( "%d%d", &u, &v );
            graph[ u ].push_back( v );
            graph[ v ].push_back( u );
        }
        for ( i = 1; i <= N; ++i ) {
            if ( !visited[ i ] ) {
                bfs( i, graph, N, visited );
            }
            if ( found == true ) {
                break;
            }
        }
        if ( found ) {
            printf( "Scenario #%d:\nSuspicious bugs found!\n", j );
        }
        else {
            printf( "Scenario #%d:\nNo suspicious bugs found!\n", j );
        }
    }
    return 0;
}
