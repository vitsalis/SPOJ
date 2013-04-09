#include <cstdio>
#include <cstring>
#define N 200000 

using namespace std;

struct node {
    int children[ 100 ];
    int wordcount;
};

node trie[ N + 1 ];
int trncnt, copied[ 30001 ];

void init( int n, int* copied ) {
    trncnt = 1;
    int i;
    for ( i = 0; i <= n; ++i ) {
        copied[ i ] = 0;
    }
    for ( i = 0; i < N; ++i ) {
        for ( int j = 0; j < 100; ++j ) {
            trie[ i ].children[ j ] = 0;
        }
        trie[ i ].wordcount = 0;
    }
}

void add( char* word, int len ) {
    int i, curNode = 1, nextNode;
    for ( i = 0; i < len; ++i ) {
        nextNode = trie[ curNode ].children[ word[ i ] ];
        if ( nextNode == 0 ) {
            trncnt++;
            trie[ curNode ].children[ word[ i ] ] = trncnt;
            curNode = trncnt;
        }
        else {
            curNode = nextNode;
        }
    }
    if ( trie[ curNode ].wordcount == 0 ) {
        trie[ curNode ].wordcount++;
        copied[ 0 ]++;
    }
    else {
        copied[ trie[ curNode ].wordcount - 1 ]--;
        copied[ trie[ curNode ].wordcount ]++;
        trie[ curNode ].wordcount++;
    }
}

void remove( char* word, int len ) {
    int i, curNode = 1;
    for ( i = 0; i < len; ++i ) {
        curNode = trie[ curNode ].children[ word[ i ] - 'a' ];
    }
    trie[ curNode ].wordcount--;
}

bool check( char* word, int len ) {
    int i, curNode = 1;
    for ( i = 0; i < len; ++i ) {
        curNode = trie[ curNode ].children[ word[ i ] - 'a' ];
        if ( curNode == 0 ) {
            return false;
        }
    }
    return trie[ curNode ].wordcount;
}

int main() {
    int n, m, len, i;
    char s[ 30 ];
    while ( 1 ) {
        scanf( "%d%d", &n, &m );
        if ( n == 0 && m == 0 ) {
            break;
        }
        init( n, copied );
        for ( i = 0; i < n; ++i ) {
            scanf( "%s", s );
            add( s, strlen( s ) );
        }
        for ( i = 0; i < n; ++i ) {
            printf( "%d\n", copied[ i ] );
        }
    }
    return 0;
}
