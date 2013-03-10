#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int t;
    long long int n;
    scanf( "%d", &t );
    while ( t > 0 ) {
        scanf( "%lld", &n );
        if ( n % 2 == 0 ) {
            printf( "%lld\n", n / 2 );
        }
        else {
            printf( "%lld\n", n / 2 + 1 );
        }
        --t;
    }
    return 0;
}
