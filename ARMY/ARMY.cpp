#include <cstdio>
#include <queue>

using namespace std;

void merge( int* A, int beg, int mid, int end ) {
	int i;
	queue<int> a, b, c;
	for ( i = beg; i <= mid; ++i ) {
		a.push( A[ i ] );
	}
	for ( i = mid + 1; i <= end; ++i ) {
		b.push( A[ i ] );
	}

	while ( !a.empty() && !b.empty() ) {
		if ( a.front() < b.front() ) {
			c.push( a.front() );
			a.pop();
		}
		else {
			c.push( b.front() );
			b.pop();
		}
	}
	while ( !a.empty() ) {
		c.push( a.front() );
		a.pop();
	}
	while ( !b.empty() ) {
		c.push( b.front() );
		b.pop();
	}
	i = beg;
	while ( !c.empty() ) {
		A[ i ] = c.front();
		++i;
		c.pop();
	}
}

void mergesort( int* A, int beg, int end ) {
	if ( beg < end ) {
		int mid = ( beg + end ) / 2;
		mergesort( A, beg, mid );
		mergesort( A, mid + 1, beg );
		merge( A, beg, mid, end );
	}
}

int main() {
	FILE *fin = fopen( "ARMY.in", "r" );
	FILE *fout = fopen( "ARMY.out", "w" );
	int t;
	fscanf( stdin, "%d", &t );
	int NG, MG, i, j;
	int G[ 100000 ], M[ 100000 ];
	queue<int> g, m;

	for ( i = 0; i < t; ++i ) {
		fscanf( stdin, "%d%d", &NG, &MG );
		for ( j = 0; j < NG; ++j ) {
			fscanf( stdin, "%d", G + j );
		}
		for ( j = 0; j < MG; ++j ) {
			fscanf( stdin, "%d", M + j );
		}
		mergesort( G, 0, NG - 1 );
		mergesort( M, 0, MG - 1 );

		for ( j = 0; j < NG; ++j ) {
			g.push( G[ j ] );
		}
		for ( j = 0; j < MG; ++j ) {
			m.push( M[ j ] );
		}
		while ( !m.empty() && !g.empty() ) {
			if ( m.front() <= g.front() ) {
				m.pop();
			}
			else {
				g.pop();
			}
		}
		if ( m.empty() ){
			fprintf( stdout, "Godzilla\n" );
			while ( !g.empty() ) {
				g.pop();
			}
		}
		else if ( g.empty() ) {
			fprintf( stdout, "MechaGodzilla\n" );
			while ( !m.empty() ) {
				m.pop();
			}
		}
	}	
}
