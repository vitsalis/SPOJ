#include <cstdio>
#include <cstring>
#include <cstdlib>
 
using namespace std;
 
struct node {
        int children[ 10 ];
        char isWord;
};
 
const int N = 110000;
 
node Trie[ N + 1 ];
int trieNodeCount;
 
void initialize() {
	trieNodeCount = 1;

	for ( int i = 0; i <= N; ++i ) {
		for ( int j = 0; j < 10; ++j ) {
			Trie[ i ].children[ j ] = 0;
		}
	}
}
 
void add( char *word, int length ) {
	int i, curNode = 1, nextNode;
	for ( i = 0; i < length; ++i ) {
		nextNode = Trie[ curNode ].children[ word[ i ] - '0' ];
		if ( nextNode == 0 ) {
			++trieNodeCount;
			Trie[ curNode ].children[ word[ i ] - '0' ] = trieNodeCount;
			curNode = trieNodeCount;
		}
		else {
			curNode = nextNode;
		}
	}
}
 
bool check( char *word, int length ) {
	int i, curNode = 1, nextNode;
    for ( i = 0; i < length; ++i ) {
		curNode = Trie[ curNode ].children[ word[ i ] - '0' ];
		if ( curNode == 0 ) {
			return false;
		}
	}
	for ( i = 0; i < 10; ++i ) {
		if ( Trie[ curNode ].children[ i ] ) {
			return true;
		}
	}
	return false;
}
 
int length( char *s ) {
        int count = 0, i;
        for ( i = 0; s[ i ] != '\0'; ++i ) {
                ++count;
        }
        return count;
}
 
int main() {
	int t, n, i;
	bool found = false;
	scanf( "%d", &t );
	while ( t > 0 ) {
		scanf( "%d", &n );
		initialize();
		char s[ n + 1 ][ 12 ];
		for ( i = 0; i < n; ++i ) {
			scanf( "%s", s[ i ] );
			add( s[ i ], length( s[ i ] ) );
		}
		for ( i = 0; i < n; ++i ) {
			if ( check( s[ i ], length( s[ i ] ) ) ) {
				found = true;
				break;
			}
		}
		if ( found ) {
			printf( "NO\n" );
		}
		else {
			printf( "YES\n" );
		}
		found = false;
		--t;
	}
}
