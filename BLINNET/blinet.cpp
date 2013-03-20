#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct edge {
    int u;
    int v;
    int w;
};

bool operator <( edge a, edge b ) {
    return a.w > b.w;
}

int P[ 10001 ], rank[ 10001 ];

void makeSet( int u ) {
    P[ u ] = u;
    rank[ u ] = 1;
}

int findSet( int u ) {
    if ( P[ u ] != u ) {
        P[ u ] = findSet( P[ u ] );
    }
    return P[ u ];
}

void uni( int u, int v ) {
    u = findSet( u );
    v = findSet( v );
    if ( rank[ u ] > rank[ v ] ) {
        P[ v ] = u;
    }
    else {
        P[ u ] = v;
        if ( rank[ u ] == rank[ v ] ) {
            rank[ v ] += 1;
        }
    }
}

void kruskal( priority_queue< edge > &q, int N ) {
    int i;
    for ( i = 1; i <= N; ++i ) {
        makeSet( i );
    }
    queue< int > mst;
    while ( !q.empty() ) {
        edge p = q.top();
        q.pop();
        if ( findSet( p.u ) != findSet( p.v ) ) {
            mst.push( p.w );
            uni( p.u, p.v );
        }
    }
    int sum = 0;
    while ( !mst.empty() ) {
        sum += mst.front();
        mst.pop();
    }
    printf( "%d\n", sum );
}

int main() {
    map< string, int > mymap;
    char s[ 20 ];
    int i, N, v, w, j, t, lim;
    scanf( "%d", &t );
    priority_queue< edge > q; 
    while ( t ) {
        scanf( "%d", &N );
        for ( i = 1; i <= N; ++i ) {
            scanf( "%s", s );
            scanf( "%d", &lim );
            for ( j = 0; j < lim; ++j ) {
                scanf( "%d%d", &v, &w );
                q.push( ( edge ) { i, v, w } );
            }
        }
        kruskal( q, N );
        --t;
    }
    return 0;
}
