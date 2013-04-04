#include <cstdio>
#include <queue>

using namespace std;

struct cord {
    int x;
    int y;
    int h;
};

char build[ 2 ][ 100001 ];
int H, K;

void visit( int x, int y, cord p, bool visited[][ 100001 ], int dist[][ 100001 ], queue< cord > &q ) {
    if ( x < 0 || x >= 2 || y >= H || y < 0 || visited[ x ][ y ] || build[ x ][ y ] == 'X' ) {
        return;
    }
    else {
        dist[ x ][ y ] = dist[ p.x ][ p.y ] + 1;
        q.push( ( cord ) { x, y, p.h + 1 } );
        visited[ x ][ y ] = true;
    }
}

int bfs() {
    int dist[ 2 ][ 100001 ], i;
    bool visited[ 2 ][ 100001 ];
    for ( i = 0; i < H; ++i ) {
        visited[ 0 ][ i ] = visited[ 1 ][ i ] = false;
    }
    queue< cord > q;
    q.push( ( cord ) { 0, 0, 0 } );
    dist[ 0 ][ 0 ] = 0;
    visited[ 0 ][ 0 ] = true;
    while ( !q.empty() ) {
        cord p = q.front();
        q.pop();
		if ( p.h > p.y ) {
			continue;
		}
        if ( p.y + K >= H || p.y + 1 >= H ) {
            return dist[ p.x ][ p.y ] + 1;
        }
        visit( p.x, p.y + 1, p, visited, dist, q );
        visit( p.x, p.y - 1, p, visited, dist, q );
        visit( p.x + 1, p.y + K, p, visited, dist, q );
        visit( p.x - 1, p.y + K, p, visited, dist, q );
    }
    return -1;
}

int main() {
    int t, i;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d%s%s", &H, &K, build[ 0 ], build[ 1 ] );
        int ans = bfs();
        if ( ans >= 0 ) {
            printf( "%d\n", ans );
        }
        else {
            printf( "NO\n" );
        }
    }
    return 0;
}
