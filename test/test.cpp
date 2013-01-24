#include <cstdio>

using namespace std;

int main() {
	int i;

	while( 1 ) {
		fscanf( stdin, "%d", &i );
		if ( i == 42 ) {
			break;
		}
		fprintf( stdout, "%d\n", i );
	}

	return 0;
}
