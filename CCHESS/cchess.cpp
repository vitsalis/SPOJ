#include <cstdio>
#include <queue>

using namespace std;

struct pos {
	int x;
	int y;
};

int xx, yy;
const int N = 8;

bool check( int x, int y, bool visited[][ 9 ], int cost[][ 9 ] ) {
	if ( x < 0 || x >= N ) return false;
	if ( y < 0 || y >= N ) return false;
	if ( cost[ xx ][ yy ] + ( ( xx * x ) + ( yy * y ) ) >= cost[ x ][ y ] ) return false;
	return true;
}

void bfs( int a, int b, int c, int d ) {
	bool visited[ 9 ][ 9 ];
	int cost[ 9 ][ 9 ], i, j;
	queue< pos > q;
	q.push( ( pos ) { a, b } );
	for ( i = 0; i <= 8; ++i ) {
		for ( j = 0; j <= 8; ++j ) {
			cost[ i ][ j ] = 100000000;
			visited[ i ][ j ] = false;
		}
	}
	cost[ a ][ b ] = 0;

	while ( !q.empty() ) {
		pos p = q.front();
		q.pop();
		xx = p.x;
		yy = p.y;
		visited[ xx ][ yy ] = true;
		if ( check( xx - 1, yy + 2, visited, cost ) ) {
			q.push( ( pos ) { xx - 1, yy + 2 } );
			cost[ xx - 1 ][ yy + 2 ] = cost[ xx ][ yy ] + xx * ( xx - 1 ) + yy * ( yy + 2 );
		}
		if ( check( xx + 1, yy + 2, visited, cost ) ) {
			q.push( ( pos ) { xx + 1, yy + 2 } );
			cost[ xx + 1 ][ yy + 2 ] = cost[ xx ][ yy ] + xx * ( xx + 1 ) + yy * ( yy + 2 );
		}
		if ( check( xx - 1, yy - 2, visited, cost ) ) {
			q.push( ( pos ) { xx - 1, yy - 2 } );
			cost[ xx - 1 ][ yy - 2 ] = cost[ xx ][ yy ] + xx * ( xx - 1 ) + yy * ( yy - 2 );
		}
		if ( check( xx + 1, yy - 2, visited, cost ) ) {
			q.push( ( pos ) { xx + 1, yy - 2 } );
			cost[ xx + 1 ][ yy - 2 ] = cost[ xx ][ yy ] + xx * ( xx + 1 ) + yy * ( yy - 2 );
		}
		if ( check( xx - 2, yy + 1, visited, cost ) ) {
			q.push( ( pos ) { xx - 2, yy + 1 } );
			cost[ xx - 2 ][ yy + 1 ] = cost[ xx ][ yy ] + xx * ( xx - 2 ) + yy * ( yy + 1 );
		}
		if ( check( xx + 2, yy + 1, visited, cost ) ) {
			q.push( ( pos ) { xx + 2, yy + 1 } );
			cost[ xx + 2 ][ yy + 1 ] = cost[ xx ][ yy ] + xx * ( xx + 2 ) + yy * ( yy + 1 );
		}
		if ( check( xx - 2, yy - 1, visited, cost ) ) {
			q.push( ( pos ) { xx - 2, yy - 1 } );
			cost[ xx - 2 ][ yy - 1 ] = cost[ xx ][ yy ] + xx * ( xx - 2 ) + yy * ( yy - 1 );
		}
		if ( check( xx + 2, yy - 1, visited, cost ) ) {
			q.push( ( pos ) { xx + 2, yy - 1 } );
			cost[ xx + 2 ][ yy - 1 ] = cost[ xx ][ yy ] + xx * ( xx + 2 ) + yy * ( yy - 1 );
		}
	}
	if ( !visited[ c ][ d ] ) {
		printf( "-1\n" );
		return;
	}
	printf( "%d\n", cost[ c ][ d ] );
}

int main() {
	int a, b, c, d;

	while ( scanf( "%d", &a ) != EOF ) {
		scanf( "%d%d%d", &b, &c, &d );
		bfs( a, b, c, d );
	}	

	return 0;
}
