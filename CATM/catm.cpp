#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int mdist[ 100 ][ 100 ];
int cdist[ 100 ][ 100 ];
int n, m;

struct cord {
	int x;
	int y;
};

void cbfs( cord cat ) {
	bool visited[ n ][ m ];
	int i, j;
	for ( i = 0; i < n; ++i ) {
		for ( j = 0; j < n; ++j ) {
			visited[ i ][ j ] = false;
		}
	}
	cat.x -= 1;
	cat.y -= 1;
	queue< cord > q;
	q.push( cat );
	cdist[ cat.x ][ cat.y ] = 0;
	while ( !q.empty() ) {
		cord p = q.front();
		q.pop();
		if ( !visited[ p.x ][ p.y ] ) {
			visited[ p.x ][ p. y ] = true;
			if ( p.x + 1 < n && cdist[ p.x + 1 ][ p.y ] > cdist[ p.x ][ p.y ] + 1 ) {
				q.push( ( cord ) { p.x + 1, p.y } );
				cdist[ p.x + 1 ][ p.y ] = cdist[ p.x ][ p.y ] + 1;
			}
			if ( p.x - 1 >= 0 && cdist[ p.x - 1 ][ p.y ] > cdist[ p.x ][ p.y ] + 1 ) {
				q.push( ( cord ) { p.x - 1, p.y } );
				cdist[ p.x - 1 ][ p.y ] = cdist[ p.x ][ p.y ] + 1;
			}
			if ( p.y + 1 < m && cdist[ p.x ][ p.y + 1 ] > cdist[ p.x ][ p.y ] + 1 ) {
				q.push( ( cord ) { p.x, p.y + 1 } );
				cdist[ p.x ][ p.y + 1 ] = cdist[ p.x ][ p.y ] + 1;
			}
			if ( p.y - 1 >= 0 && cdist[ p.x ][ p.y - 1 ] > cdist[ p.x ][ p.y ] + 1 ) {
				q.push( ( cord ) { p.x, p.y - 1 } );
				cdist[ p.x ][ p.y - 1 ] = cdist[ p.x ][ p.y ] + 1;
			}
		}
	}
}

void mbfs( cord mouse ) {
	bool visited[ n ][ m ];
	int i, j;
	for ( i = 0; i < n; ++i ) {
		for ( j = 0; j < n; ++j ) {
			visited[ i ][ j ] = false;
		}
	}

	queue< cord > q;
	mouse.x -= 1;
	mouse.y -= 1;
	q.push( mouse );
	mdist[ mouse.x ][ mouse.y ] = 0;
	while ( !q.empty() ) {
		cord p = q.front();
		q.pop();
		if ( !visited[ p.x ][ p.y ] ) {
			visited[ p.x ][ p. y ] = true;
			if ( p.x + 1 < n && mdist[ p.x + 1 ][ p.y ] > mdist[ p.x ][ p.y ] + 1 ) {
				q.push( ( cord ) { p.x + 1, p.y } );
				mdist[ p.x + 1 ][ p.y ] = mdist[ p.x ][ p.y ] + 1;
			}
			if ( p.x - 1 >= 0 && mdist[ p.x - 1 ][ p.y ] > mdist[ p.x ][ p.y ] + 1 ) {
				q.push( ( cord ) { p.x - 1, p.y } );
				mdist[ p.x - 1 ][ p.y ] = mdist[ p.x ][ p.y ] + 1;
			}
			if ( p.y + 1 < m && mdist[ p.x ][ p.y + 1 ] > mdist[ p.x ][ p.y ] + 1 ) {
				q.push( ( cord ) { p.x, p.y + 1 } );
				mdist[ p.x ][ p.y + 1 ] = mdist[ p.x ][ p.y ] + 1;
			}
			if ( p.y - 1 >= 0 && mdist[ p.x ][ p.y - 1 ] > mdist[ p.x ][ p.y ] + 1 ) {
				q.push( ( cord ) { p.x, p.y - 1 } );
				mdist[ p.x ][ p.y - 1 ] = mdist[ p.x ][ p.y ] + 1;
			}
		}
	}
}

int main() {
	scanf( "%d%d", &n, &m );
	int t;
	scanf( "%d", &t );
	int i, j;
	cord cat1, cat2, mouse;
	bool found;

	while ( t > 0 ) {
		found = false;
		for ( i = 0; i < n; ++i ) {
			for ( j = 0; j < m; ++j ) {
				mdist[ i ][ j ] = cdist[ i ][ j ] = 1000000;
			}
		}
		scanf( "%d%d%d%d%d%d", &mouse.x, &mouse.y, &cat1.x, &cat1.y, &cat2.x, &cat2.y );
		cbfs( cat1 );
		cbfs( cat2 );
		mbfs( mouse );
		if ( !found ) {
			for ( i = 0; i < n; ++i ) {
				if ( mdist[ i ][ 0 ] < cdist[ i ][ 0 ] || mdist[ i ][ m - 1 ] < cdist[ i ][ m - 1 ] ) {
					printf( "YES\n" );
					found = true;
					break;
				}
			}
		}
		if ( !found ) {
			for ( j = 0; j < m; ++j ) {
				if ( mdist[ 0 ][ j ] < cdist[ 0 ][ j ] || mdist[ n - 1 ][ j ] < cdist[ n - 1 ][ j ] ) {
					printf( "YES\n" );
					found = true;
					break;
				}
			}
		}
		if ( !found ) {
			printf( "NO\n" );
		}
		--t;
	}

	return 0;
}
