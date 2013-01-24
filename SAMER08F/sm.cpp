#include <cstdio>

using namespace std;

int main() {
	long long int num = 0;
	int n;
	while ( 1 ) {
		scanf( "%d", &n );
		if ( n == 0 ) {
			break;
		}
		while ( n > 0 ) {
			num += n * n;
			--n;
		}
		printf( "%lld\n", num );
		num = 0;
	}
}
