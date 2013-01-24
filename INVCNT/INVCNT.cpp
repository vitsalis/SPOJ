#include <cstdio>
#include <queue>

using namespace std;

int A[ 200000 ];

long long int count = 0;
void merge(int beg, int mid, int end) {
	queue<int> a, b, c;
	int i;
	for ( i = beg; i <= mid; ++i ) {
		a.push( A[ i ] );
	}
	for ( i = mid + 1; i<= end; ++i ) {
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
			count += a.size();
		}
	}
	if ( !a.empty() ) {
		while ( !a.empty() ) {
			c.push( a.front() );
			a.pop();
		}
	}
	else {
		while ( !b.empty() ) {
			c.push( b.front() );
			b.pop();
		}
	}
	i = beg;
	while( !c.empty() ) {
		A[ i ] = c.front();
		++i;
		c.pop();
	}
}

void mergesort( int beg, int end ) {
	if ( beg < end ) {
		int mid, i = 0;
		mid = ( beg + end ) / 2;
		mergesort( beg, mid );
		mergesort( mid + 1, end );
		merge( beg, mid, end );
	}
}

int main() {
	int N, j, k = 0;

	scanf( "%d", &j );
	while ( k < j ) {

		scanf( "%d", &N );

		for ( int i = 0; i < N; ++i ) {
			scanf( "%d", &A[ i ] );
		}

		mergesort( 0, N - 1 );
		printf( "%lld\n", count );

		count = 0;
		++k;
	}
}
