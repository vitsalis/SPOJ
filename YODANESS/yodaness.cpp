#include <cstdio>
#include <map>
#include <string>
#include <queue>

using namespace std;

long long int count;
int array[ 30000 ];

void merge( int beg, int mid, int end ) {
	int i;
	queue< int > a, b, c;
	for ( i = beg; i <= mid; ++i ) {
		a.push( array[ i ] );
	}
	for ( i = mid + 1; i <= end; ++i ) {
		b.push( array[ i ] );
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
		array[ i ] = c.front();
		++i;
		c.pop();
	}
}

void mergesort( int beg, int end ) {
	if ( beg < end ) {
		int mid = ( beg + end ) / 2;
		mergesort( beg, mid );
		mergesort( mid + 1, end );
		merge( beg, mid, end );
	}
}

int main() {
	int t, N, i;
	char s[ 30001 ];
	scanf( "%d", &t );
	map< string, int > mymap;
	while ( t > 0 ) {
		string word;
		scanf( "%d", &N );
		for ( i = 0; i < N; ++i ) {
			scanf( "%s", s );
			word = s;
			mymap[ word ] = i + 1;
		}
		for ( i = 0; i < N; ++i ) {
			scanf( "%s", s );
			word = s;
			array[ i ] = mymap[ word ];
		}
		count = 0;
		mergesort( 0, N - 1 );
		printf( "%lld\n", count );
		--t;
	}

	return 0;
}
