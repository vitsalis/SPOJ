#include <cstdio>
#include <queue>

using namespace std;

long long int count;

void merge( int beg, int mid, int end, int array[] ) {
    int i;
    queue< int > a, b, c;
    for ( i = beg; i <= mid; ++i ) {
        a.push( array[ i ] );
    }
    for ( i = mid + 1; i <= end; ++i ) {
        b.push( array[ i ] );
    }
    while ( !a.empty() && !b.empty() ) {
        if ( a.front() < b.front() ) {
            c.push( a.front() );
            count += ( long long ) a.front() * b.size();
            a.pop();
        }
        else {
            c.push( b.front() );
            b.pop();
        }
    }
    while ( !a.empty() ) {
        c.push( a.front() );
        a.pop();
    }
    while ( !b.empty() ) {
        c.push( b.front() );
        b.pop();
    }
    i = beg;
    while ( !c.empty() ) {
        array[ i++ ] = c.front();
        c.pop();
    }
}

void mergeSort( int beg, int end, int array[] ) {
    if ( beg < end ) {
        int mid = ( beg + end ) / 2;
        mergeSort( beg, mid, array );
        mergeSort( mid + 1, end, array );
        merge( beg, mid, end, array );
    }
}

int main() {
    int t, N, array[ 100000 ], i;
    scanf( "%d", &t );
    while ( t > 0 ) {
        scanf( "%d", &N );
        for ( i = 0; i < N; ++i ) {
            scanf( "%d", array + i );
        }
        count = 0;
        mergeSort( 0, N - 1, array );
        printf( "%lld\n", count );
        --t;
    }
    return 0;
}
