/* Problem 51 = 121313 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../algorithms.h"

#define MAX_PRIME 1000000

int main() {
    char *sieve = (char *)calloc(MAX_PRIME, sizeof(char));
    char prime[7];
    int primes;
    char digits[] = "0123456789";
    char *digitPtr;
    char *digitToReplacePtr;
    int answer = 0;
    int i;
    char digit;

    sieve_primes(sieve, MAX_PRIME);

    for (i = 0; !answer && i < MAX_PRIME; i++) {
        if (!sieve[i]) {
            sprintf(prime, "%d", i);

            for (digit = '0'; digit <= '2'; digit++) {
                if (strchr(prime, digit)) {
                    primes = 1;
                    digitPtr = digits;

                    while (*digitPtr) {
                        if (*digitPtr > digit) {
                            while ((digitToReplacePtr = strchr(prime, digit))) {
                                *digitToReplacePtr = *digitPtr;
                            }

                            primes += !sieve[atoi(prime)];
                            sprintf(prime, "%d", i);
                        }

                        ++digitPtr;
                    }

                    if (primes == 8) {
                        answer = i;
                    }
                }

                sprintf(prime, "%d", i);
            }
        }
    }

    free(sieve);

    printf("%d", answer);
    
    return 0;
}
