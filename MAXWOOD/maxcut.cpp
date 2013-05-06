#include <cstdio>
#include <queue>

using namespace std;

struct pos {
    int x, y, dir, cut;
};

char map[ 300 ][ 300 ];
int N, M, m, dist[ 300 ][ 300 ];

bool check( int x, int y, int dir ) {
    if ( dir == 0 ) {
        if ( x - 1 > 0 && y - 1 > 0 ) {
            if ( map[ x - 1 ][ y ] == '#' && map[ x ][ y - 1 ] == '#' ) {
                return false;
            }
        }
        else if ( x - 1 > 0 ) {
            if ( map[ x - 1 ][ y ] == '#' ) {
                return false;
            }
        }
        else if ( y - 1 > 0 ) {
            if ( map[ x ][ y - 1 ] == '#' ) {
                return false;
            }
        }
    }
    else {
        if ( x - 1 > 0 && y + 1 <= M ) {
            if ( map[ x - 1 ][ y ] == '#' && map[ x ][ y + 1 ] == '#' ) {
                return false;
            }
        }
        else if ( x - 1 > 0 ) {
            if ( map[ x - 1 ][ y ] == '#' ) {
                return false;
            }
        }
        else if ( y + 1 <= M ) {
            if ( map[ x ][ y + 1 ] == '#' ) {
                return false;
            }
        }
    }
    return true;
}

void visit( int x, int y, int dir ) {
    dist[ x ][ y ] = 0;
    if ( map[ x ][ y ] == '#' ) {
        return;
    }
    if ( dir == 0 ) {
        dist[ x ][ y ] = max( dist[ x ][ y - 1 ], dist[ x - 1 ][ y ] );
    }
    else {
        dist[ x ][ y ] = max( dist[ x ][ y + 1 ], dist[ x - 1 ][ y ] );
    }
    if ( map[ x ][ y ] == 'T' ) {
        dist[ x ][ y ] += 1;
    }
}

/*void visit( queue< pos > &q, int x, int y, int dir, int cut ) {
    if ( x >= N || y >= M || y < 0 || map[ x ][ y ] == '#' ) {
        return;
    }
    if ( map[ x ][ y ] == 'T' ) {
        cut += 1;
        if ( cut > m ) {
            m = cut;
        }
    }
    q.push( ( pos ) { x, y, dir, cut } );
}

void bfs() {
    queue< pos > q;
    if ( map[ 0 ][ 0 ] != 'T' ) {
        q.push( ( pos ) { 0, 0, 0, 0 } );
    }
    else {
        q.push( ( pos ) { 0, 0, 0, 1 } );
        m = 1;
    }
    while ( !q.empty() ) {
        pos p = q.front();
        q.pop();
        if ( map[ p.x ][ p.y ] == '#' ) {
            continue;
        }
        if ( p.dir == 0 ) {
            visit( q, p.x, p.y + 1, 0, p.cut );
            visit( q, p.x + 1, p.y, 1, p.cut );
        }
        else {
            visit( q, p.x, p.y - 1, 1, p.cut );
            visit( q, p.x + 1, p.y, 0, p.cut );
        }
    }
}*/

int main() {
    int t, i, j;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &N, &M );
        for ( i = 0; i <= N + 1; ++i ) {
            for ( j = 0; j <= M + 1; ++j ) {
                dist[ i ][ j ] = 0;
            }
        }
        for ( i = 1; i <= N; ++i ) {
            scanf( "%*c" );
            for ( j = 1; j <= M; ++j ) {
                scanf( "%c", map[ i ] + j );
            }
        }
        m = 0;
        for ( i = 1; i <= N; ++i ) {
            if ( i % 2 != 0 ) {
                for ( j = 1; j <= M; ++j ) {
                    if ( check( i, j, 0 ) ) {
                        visit( i, j, 0 );
                    }
                    else {
                        map[ i ][ j ] = '#';
                    }
                }
            }
            else {
                for ( j = M; j > 0; --j ) {
                    if ( check( i, j, 1 ) ) {
                        visit( i, j, 1 );
                    }
                    else {
                        map[ i ][ j ] = '#';
                    }
                }
            }
        }
        for ( i = 1; i <= N; ++i ) {
            for ( j = 1; j <= M; ++j ) {
                if ( dist[ i ][ j ] > m ) {
                    m = dist[ i ][ j ];
                }
            }
        }
        printf( "%d\n", m );
    }
    return 0;
}
