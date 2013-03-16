#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int t;
    int a, b, c;
    double x, beg, end;
    scanf( "%d", &t );
    while ( t ) {
        scanf( "%d%d%d", &a, &b, &c );
        beg = 0;
        end = c;
        int count = 0;
        while ( count <= 100 ) {
            x = ( beg + end ) / 2; 
            ++count;
            if ( a * ( x ) + b * sin( x ) > c ) {
                end = x;
            }
            else if ( a * x + b * sin( x ) < c ) {
                beg = x;
            }
        }
        printf( "%0.6lf\n", x );
        --t;
    }
    return 0;
}
