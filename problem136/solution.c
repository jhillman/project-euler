/* Problem 136 = 2544559 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

int main() {
    int maximum = 50000000;
    char *sieve = (char *)calloc(maximum, sizeof(char));
    int number;
    int prime;
    int answer = 0;

    sieve_primes(sieve, maximum);

    for (number = 2; number < maximum; number++) {
        if (!sieve[number]) {
            prime = number;

            if (prime % 4 == 3) {
                ++answer;
            }

            prime *= 4;

            if (prime < maximum) {
                ++answer;

                if (prime * 4 < maximum) {
                    ++answer;
                }
            }
        }
    }

    free(sieve);

    printf("%d", answer);

    return 0;
}
