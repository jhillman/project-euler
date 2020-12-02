/* Problem 130 = 149253 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    char *sieve = (char *)calloc(1000000, sizeof(char));
    int n = 2;
    int k;
    int divisor;
    int count = 0;
    int answer = 0;

    sieve_primes(sieve, 1000000);

    while (count < 25) {
        if (gcd(10, n) == 1 && sieve[n]) {
            k = 1;
            divisor = n * 9;

            while (modulus_power(10, k, divisor) != 1) {
                ++k;
            }

            if ((n - 1) % k == 0) {
                answer += n;
                ++count;
            }
        }

        ++n;
    }

    free(sieve);

    printf("%d", answer);

    return 0;
}
