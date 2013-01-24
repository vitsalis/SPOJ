#include <cstdio>

using namespace std;

long long int rev( long long int num ) {
	long long int reved = num % 10;
	num = num / 10;

	while ( num != 0 ) {
		reved = ( reved * 10 ) + ( num % 10 );
		num = num / 10;
	}
	return reved;
}

int main() {
	int N;
	FILE *fin = fopen( "palin.in", "r" );
	FILE *fout = fopen( "palin.out", "w" );

	fscanf( fin, "%d", &N );
	int i = 0;
	long long int num;
	while ( i < N ) {
		fscanf( fin, "%lld", &num );
		++num;
		while ( 1 ) {
			if ( rev( num ) == num ) {
				fprintf( fout, "%lld\n", num );
				break;
			}
			++num;
		}
		++i;
	}

	return 0;
}
