#include <cstdio>
#include <queue>

#define INF 1000000

using namespace std;

struct edge {
    int x;
    int y;
    int w;
};

bool operator <( edge a, edge b ) {
    return a.w < b.w;
}

int n, m;

void visit( int x, int y, int dista, int dist[][ 25 ], int dim[][ 25 ], priority_queue< edge > &q, bool block[][ 25 ] ) {
    if ( x < 0 || x >= n || y < 0 || y >= m || block[ x ][ y ] ) {
        return;
    }
    if ( dista + dim[ x ][ y ] < dist[ x ][ y ] ) {
        dist[ x ][ y ] = dista + dim[ x ][ y ];
        q.push( ( edge ) { x, y, dim[ x ][ y ] } );
    }
}

void dijkstra( int dim[][ 25 ], edge S, edge T, bool block[][ 25 ] ) {
    int dist[ 25 ][ 25 ], i, j;
    for ( i = 0; i < n; ++i ) {
        for ( j = 0; j < m; ++j ) {
            dist[ i ][ j ] = INF;
        }
    }
    priority_queue< edge > q;
    q.push( S );
    dist[ S.x ][ S.y ] = 0;
    while ( !q.empty() ) {
        edge p = q.top();
        q.pop();
        visit( p.x + 1, p.y, dist[ p.x ][ p.y ], dist, dim, q, block );
        visit( p.x - 1, p.y, dist[ p.x ][ p.y ], dist, dim, q, block );
        visit( p.x, p.y + 1, dist[ p.x ][ p.y ], dist, dim, q, block );
        visit( p.x, p.y - 1, dist[ p.x ][ p.y ], dist, dim, q, block );
    }
    printf( "%d\n", dist[ T.x ][ T.y ] );
}

int main() {
    int i, j, dim[ 25 ][ 25 ];
    bool block[ 25 ][ 25 ];
    edge source, dest;
    char c;
    while ( 1 ) {
        scanf( "%d%d", &m, &n );
        if ( m == 0 && n == 0 ) {
            break;
        }
        for ( i = 0; i < n; ++i ) {
            scanf( "%*c" );
            for ( j = 0; j < m; ++j ) {
                scanf( "%c", &c );
                if ( c == 'S' ) {
                    dim[ i ][ j ] = 0;
                    source.x = i;
                    source.y = j;
                    source.w = 0;
                    block[ i ][ j ] = false;
                }
                else if ( c == 'D' ) {
                    dim[ i ][ j ] = 0;
                    dest.x = i;
                    dest.y = j;
                    dest.w = 0;
                    block[ i ][ j ] = false;
                }
                else if ( c == 'X' ) {
                    block[ i ][ j ] = true;
                }
                else {
                    block[ i ][ j ] = false;
                    dim[ i ][ j ] = c - '0';
                }
                
            }
        }
        dijkstra( dim, source, dest, block );
    }
    return 0;
}
