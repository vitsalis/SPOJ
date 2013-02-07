#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M, D, L;
	scanf( "%d%d%d%d", &N, &M, &D, &L );
	int array[ N ];
	vector< int > lanes[ M ];
	int i, j;
	for ( i = 0; i < N; ++i ) {
		scanf( "%d", array + i );
	}
	sort( array, array + i );
	i = j = 0;
	int count = 0;
	while ( i < N ) {
		if ( j == M ) {
			j = 0;
		}
		if ( array[ i ] - ( D * lanes[ j ].size() ) >= L ) {
			lanes[ j ].push_back( 1 );
			++count;
		}
		++i;
		++j;
	}
	printf( "%d\n", count );

	return 0;
}
