#include <cstdio>

using namespace std;

int main() {
	int N, i, count;

	while ( 1 ) {
		scanf( "%d", &N );
		if ( N == 0 ) {
			break;
		}
		i = 1;
		count = 0;
		while ( N > 0 ) {
			N -= i;
			++count;
			i *= 2;
		}
		printf( "%d\n", count - 1 );
	}

	return 0;
}
