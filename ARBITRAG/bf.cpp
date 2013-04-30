#include <cstdio>
#include <string>
#include <map>
#include <vector>

const int INF = 0x3f3f3f3f;

using namespace std;

struct edge {
    int v;
    float w;
};

bool belford( vector< edge > graph[], int N, int S ) {
    double dist[ N + 1 ];
    int i, from, to;
    for ( i = 1; i <= N; ++i ) {
        dist[ i ] = 0;
    }
    dist[ S ] = 1;
    for ( i = 0; i <= N ; ++i ) {
        for ( from = 1; from <= N; ++from ) {
            for ( to = 0; to < graph[ from ].size(); ++to ) {
                edge k = graph[ from ][ to ];
                if ( dist[ k.v ] < k.w * dist[ from ] ) {
                    dist[ k.v ] = k.w * dist[ from ];
                }
            }
        }
    }
    if ( dist[ S ] > 1.0 ) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int N, M, i, u, v, caseno = 0;
    float w;
    char from[ 10000 ], to[ 10000 ];
    map< string, int > mymap;
    vector< edge > graph[ 31 ];
    while ( 1 ) {
        mymap.clear();
        scanf( "%d", &N );
        if ( N == 0 ) {
            break;
        }
        for ( i = 1; i <= N; ++i ) {
            scanf( "%s", from );
            mymap[ from ] = i;
            graph[ i ].clear();
        }
        scanf( "%d", &M );
        for ( i = 0; i < M; ++i ) {
            scanf( "%s%f%s", from, &w, to );
            graph[ mymap[ from ] ].push_back( ( edge ) { mymap[ to ], w } );
        }
        if ( belford( graph, N, 1 ) ) {
            printf( "Case %d: Yes\n", ++caseno );
        }
        else {
            printf( "Case %d: No\n", ++caseno );
        }
    }
    return 0;
}
