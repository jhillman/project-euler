/* Problem 187 = 17427258 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    int maximum = 100000000;
    int squareRoot = (int)(sqrt(maximum) + 1);
    char *sieve = (char *)calloc(maximum / 2, sizeof(char));
    int p;
    int q;
    int answer = 0;

    sieve_primes(sieve, maximum / 2);

    for (p = 2; p < squareRoot; p++) {
        if (!sieve[p]) {
            for (q = p; p * q < maximum; q++) {
                if (!sieve[q]) {
                    ++answer;
                }
            }
        }
    }

    free(sieve);

    printf("%d", answer);

    return 0;
}
