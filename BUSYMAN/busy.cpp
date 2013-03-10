#include <cstdio>
#include <algorithm>

using namespace std;

struct job {
    int beg;
    int end;
};

bool operator <( job a, job b ) {
    if ( a.end == b.end ) {
        return a.beg < b.beg;
    }
    return a.end < b.end;
}

int main() {
    int t, i, n, count, begi, endi;
    job jobs[ 100000 ];
    scanf( "%d", &t );
    while ( t > 0 ) {
        scanf( "%d", &n );
        for ( i = 0; i < n; ++i ) {
            scanf( "%d%d", &jobs[ i ].beg, &jobs[ i ].end );
        }
        sort( jobs, jobs + n );
        endi = -1;
        count = 0;
        for ( i = 0; i < n; ++i ) {
            if ( jobs[ i ].beg >= endi ) {
                ++count;
                endi = jobs[ i ].end;
            }
        }
        printf( "%d\n", count );
        --t;
    }
    return 0;
}
