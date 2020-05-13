#include "stdio.h"
#include "inttypes.h"

#define N 1000000

int findPrimes(int*);

int main(int argc, char** argv)
{   
    int primes[N];
    int p = findPrimes(primes);

    int64_t n;
    while(scanf("%lld", &n) != EOF) {
        if(n == 0) {
            printf("1\n");
            continue;
        }

        while(n % 2 == 0) {
            n /= 2;
        }

        int r = 1;
        int i = 0;
        while ( i < p && n != 1) {
            int count = 0;

            while(n % primes[i] == 0) {
                n /= primes[i];
                count++;
            }
            r *= count + 1; 
            i++;
        }
        r *= n != 1 ? 2 : 1;
        printf("%d\n", r);
    }

    return 0;
}

int findPrimes(int* primes) {
    char s[N] = { 0 };

    primes[0] = 2;
    int p = 1;

    int i = 2;
    while (i < N)
    {
        if(s[i] == 0) {
            primes[p++] = i;
            int j = i;
            while (j < N) {
                s[j] = 1;
                j += i+i;
            }
        }
        i++;
    }
    return p;
}

