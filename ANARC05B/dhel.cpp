#include <cstdio>
#include <cmath>

using namespace std;

struct pos {
	int x;
	int y;
};

int aN, bN, k;

int max( int a, int b ) {
	if ( a > b ) return a;
	return b;
}

void read( int N, int a[] ) {
	int i;
	for ( i = 0; i < N; ++i ) {
		scanf( "%d", a + i );
	}
}

void findInter( int a[], int b[], pos inter[] ) {
	int last = 0, o = 0, i, j;
	bool found = false;
	for ( i = 0; i < aN; ++i ) {
		for ( j = last; j < bN; ++j ) {
			if ( a[ i ] == b[ j ] ) {
				found = true;
				inter[ o++ ] = ( ( pos ) { i, j } );
				break;
			}
		}
		if ( found ) {
			last = j;
		}
		else {
			j = last;
		}
		found = false;
	}
	inter[ o ] = ( ( pos ) { -1, -1 } );
}

int findmax( int &i, int &j, int a[], int b[], pos inter[] ) {
	int asum, bsum;
	asum = bsum = 0;
	while ( i != inter[ k - 1 ].x && i < aN ) {
		asum += a[ i++ ];
	}
	while ( j != inter[ k - 1 ].y && j < bN ) {
		bsum += b[ j++ ];
	}
	return max( asum, bsum );
}

int main() {
	int a[ 100000 ], b[ 100000 ], i, j, sum;
	pos inter[ 10000 ];
	while ( 1 ) {
		sum = i = j = k = 0;
		scanf( "%d", &aN );
		if ( aN == 0 ) break;
		read( aN, a );
		scanf( "%d", &bN );
		read( bN, b );
		findInter( a, b, inter );
		while ( i < aN || j < bN ) {
			sum += findmax( i, j, a, b, inter );
			++k;
		}
		printf( "%d\n", sum );
	}

	return 0;
}
