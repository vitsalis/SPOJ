#include <cstdio>

using namespace std;

int main() {
	long long int num;
	int t;
	scanf( "%d", &t );
	while ( t > 0 ) {
		scanf( "%lld", &num );
		printf( "%lld\n", ( ( num - 1 ) * 250 ) + 192 );
		--t;
	}
}
