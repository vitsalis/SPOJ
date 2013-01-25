#include <cstdio>
#include <map>

using namespace std;

map< long long int, long long int > mymap;

unsigned long long int find( unsigned long long int n ) {
	if ( n == 0 ) {
		return 0;
	}
	if ( mymap[ n ] ) {
		return mymap[ n ];
	}
	unsigned long long int k, l, m;
	k = n / 2;
	l = n / 3;
	m = n / 4;
	unsigned long long int kf, lf, mf;
	kf = find( k );
	lf = find( l );
	mf = find( m );
	if ( kf > k ) {
		mymap[ k ] = kf;
		k = kf;
	}
	else {
		mymap[ k ] = k;
	}
	if ( lf > l ) {
		mymap[ l ] = lf;
		l = lf;
	}
	else {
		mymap[ l ] = l;
	}
	if ( mf > m ) {
		mymap[ m ] = mf;
		m = mf;
	}
	else {
		mymap[ m ] = m;
	}
	unsigned long long int nf = n;
	if ( k + l + m > nf ) {
		nf = k + l + m;
		mymap[ n ] = nf;
		return nf;
	}
	else {
		mymap[ n ] = n;
		return n;
	}
}

int main() {
	long long int n;
	while ( scanf( "%lld", &n ) ) {
		if ( n == -1 ) {
			break;
		}
		printf( "%lld\n", find( n ) );
		n = -1;
	}

	return 0;
}
