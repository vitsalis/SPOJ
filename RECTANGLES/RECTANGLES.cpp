#include <cstdio>

using namespace std;

int main() {
	int num, count = 0;
	fscanf( stdin, "%d", &num );
	for ( int i = 1; i <= num; ++i ) {
		for ( int j = i; j * i <= num; ++j ) {
			++count;
		}
	}
	fprintf( stdout, "%d", count );
	return 0;
}
