/* Problem 132 = 843296 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    char *sieve = (char *)calloc(1000000, sizeof(char));
    int p = 2;
    int count = 0;
    int answer = 0;

    sieve_primes(sieve, 1000000);

    while (count < 40) {
        if (!sieve[p]) {
            if (modulus_power(10, 1000000000, p * 9) == 1) {
                answer += p;
                ++count;
            }
        }

        ++p;
    }

    free(sieve);

    printf("%d", answer);

    return 0;
}
