/* Problem 133 = 453647705 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    char *sieve = (char *)calloc(100000, sizeof(char));
    int p;
    int n;
    long long x;
    int answer = 0;

    sieve_primes(sieve, 100000);

    for (p = 2; p < 100000; p++) {
        if (!sieve[p]) {
            n = p - 1;
            x = 10;

            while (n % 2 == 0) {
                n /= 2;
                x = modulus_power(x, 2, p);
            }

            while (n % 5 == 0) {
                n /= 5;
                x = modulus_power(x, 5, p);
            }

            if (p == 3 || x != 1) {
                answer += p;
            }
        }
    }

    free(sieve);

    printf("%d", answer);

    return 0;
}
