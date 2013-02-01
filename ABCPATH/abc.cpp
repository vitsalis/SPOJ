#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int H, W, m = 0;


struct cord {
	int x;
	int y;
};

int bfs( int array[][ 50 ], int x, int y ) {
	int dist[ 27 ], i, j;
	for ( i = 0; i <= 27; ++i ) {
		dist[ i ] = 1;
	}
	bool visited[ 50 ][ 50 ];
	for ( i = 0; i < H; ++i ) {
		for ( j = 0; j < W; ++j ) {
			visited[ i ][ j ] = false;
		}
	}
	queue< cord > q;
	q.push( ( cord ) { x, y } );
	int k, l;

	while ( !q.empty() ) {
		cord p = q.front();
		q.pop();
		k = array[ p.x ][ p.y ];
		if ( !visited[ p.x ][ p.y ] ) {
			visited[ p.x ][ p.y ] = true;
			if ( p.y + 1 < W && array[ p.x ][ p.y ] + 1 == array[ p.x ][ p.y + 1 ] ) {
				q.push( ( cord ) { p.x, p.y + 1 } );
				l = array[ p.x ][ p.y + 1 ];
				dist[ l ] = dist[ k ] + 1;
			}
			if ( p.y - 1 >= 0 && p.x < H && array[ p.x ][ p.y ] + 1 == array[ p.x ][ p.y - 1 ] ) {
				q.push( ( cord ) { p.x, p.y - 1 } );
				l = array[ p.x ][ p.y - 1 ];
				dist[ l ] = dist[ k ] + 1;
			}
			if ( p.x + 1 < H && array[ p.x ][ p.y ] + 1 == array[ p.x + 1 ][ p.y ] ) {
				q.push( ( cord ) { p.x + 1, p.y } );
				l = array[ p.x + 1 ][ p.y ];
				dist[ l ] = dist[ k ] + 1;
			}
			if ( p.x - 1 >= 0 && array[ p.x ][ p.y ] + 1 == array[ p.x - 1 ][ p.y ] ) {
				q.push( ( cord ) { p.x - 1, p.y } );
				l = array[ p.x - 1 ][ p.y ];
				dist[ l ] = dist[ k ] + 1;
			}
			if ( p.x + 1 < H && p.y + 1 < W && array[ p.x ][ p.y ] + 1 == array[ p.x + 1 ][ p.y + 1 ] ) {
				q.push( ( cord ) { p.x + 1, p.y + 1 } );
				l = array[ p.x + 1 ][ p.y + 1 ];
				dist[ l ] = dist[ k ] + 1;
			}
			if ( p.x + 1 < H && p.y - 1 >= 0 && array[ p.x ][ p.y ] + 1 == array[ p.x + 1 ][ p.y - 1 ] ) {
				q.push( ( cord ) { p.x + 1, p.y - 1 } );
				l = array[ p.x + 1 ][ p.y - 1 ];
				dist[ l ] = dist[ k ] + 1;
			}
			if ( p.x - 1 >= 0 && p.y - 1 >= 0 && array[ p.x ][ p.y ] + 1 == array[ p.x - 1 ][ p.y - 1 ] ) {
				q.push( ( cord ) { p.x - 1, p.y - 1 } );
				l = array[ p.x - 1 ][ p.y - 1 ];
				dist[ l ] = dist[ k ] + 1;
			}
			if ( p.x - 1 >= 0 && p.y + 1 < W && array[ p.x ][ p.y ] + 1 == array[ p.x - 1 ][ p.y + 1 ] ) {
				q.push( ( cord ) { p.x - 1, p.y + 1 } );
				l = array[ p.x - 1 ][ p.y + 1 ];
				dist[ l ] = dist[ k ] + 1;
			}
		}
	}
	sort( dist, dist + 27 );

	if ( dist[ 26 ] > m ) {
		m = dist[ 26 ];
	}
}

int main() {
	int i, array[ 50 ][ 50 ], j, k, count = 1;
	int apos[ 50 ][ 50 ], l = 0;
	char ab[ 27 ] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", c;

	while ( 1 ) {
		scanf( "%d%d", &H, &W );
		if ( H == 0 && W == 0 ) {
			break;
		}
		for ( i = 0; i < H; ++i ) {
			for ( j = 0; j < W; ++j ) {
				apos[ i ][ j ] = 0;
			}
		}
		scanf( "%*c" );
		for ( i = 0; i < H; ++i ) {
			for ( j = 0; j < W; ++j ) {
				scanf( "%c", &c );
				for ( k = 0; k < 27; ++k ) {
					if ( c == ab[ k ] ) {
						if ( k == 0 ) {
							apos[ i ][ j ] = 1;
						}
						array[ i ][ j ] = k;
						break;
					}
				}
			}
			scanf( "%*c" );
		}
		for ( i = 0; i < H; ++i ) {
			for ( j = 0; j < W; ++j ) {
				if ( apos[ i ][ j ] == 1 ) {
					bfs( array, i, j );
				}
			}
		}
		printf( "Case %d: %d\n", count, m );
		m = 0;
		++count;
	}

	return 0;
}
