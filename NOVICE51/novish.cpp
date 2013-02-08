#include <cstdio>

using namespace std;

int main() {
	int t, count;
	long long int num;
	scanf( "%d", &t );

	while ( t > 0 ) {
		scanf( "%lld", &num );
		count = 2;
		while ( num > 0 ) {
			++count;
			if ( num % 2 == 0 ) {
				num /= 2;
			}
			else {
				num -= 1;
			}
		}
		if ( ( count - 1 ) % 2 == 0 ) {
			printf( "Aayush\n" );
		}
		else {
			printf( "Akash\n" );
		}

		--t;
	}

	return 0;
}
