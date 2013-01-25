#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int N, array[ 1001 ], i, found = 1;
	stack< int > s;

	while ( 1 ) {
		scanf( "%d", &N );
		if ( N == 0 ) {
			break;
		}
		for ( i = 0; i < N; ++i ) {
			scanf( "%d", array + i );
		}
		for ( i = 0; i < N - 1; ++i ) {
			if ( array[ i ] > i + 1 ) {
				s.push( array[ i ] );
			}
			else if ( !s.empty() && s.top() <= i + 1 ) {
				s.pop();
			}
		}
		int curr = 0;
		while ( !s.empty() ) {
			if ( curr > s.top() && found == 1 ) {
				printf( "no\n" );
				found = 0;
			}
			curr = s.top();
			s.pop();
		}
		if ( s.empty() && found == 1) {
			printf( "yes\n" );
		}
		found = 1;
	}
}
