#include <cstdio>
#include <cmath>

using namespace std;

int rev( int num ) {
	int reved = num % 10, k = 10;
	num = num / 10;

	while ( num != 0 ) {
		reved = ( reved * k ) + ( num % 10 );
		num = num / 10;
	}
	return reved;
}

int main() {
	int i, a, b, sum, N;

	fscanf( stdin, "%d", &N );

	for ( i = 0; i < N; ++i ) {
		fscanf( stdin, "%d%d", &a, &b );
		a = rev( a );
		b = rev( b );
		sum = a + b;
		sum = rev( sum );
		fprintf( stdout, "%d\n", sum );
	}

	return 0;
}
