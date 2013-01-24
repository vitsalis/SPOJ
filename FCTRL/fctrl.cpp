#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf( "%d", &N );
    long long int num, solu = 0;

    while ( N > 0 ) {
        scanf( "%lld", &num );
        while ( num ) {
             num = num / 5;
             solu += num;
        }

        fprintf( stdout, "%lld\n", solu );
        solu = 0;
        --N;
    }
    return 0;
}
