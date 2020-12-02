/* Problem 46 = 5777 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

#define MAX_PRIME 10000
#define MAX_SQUARE 1000

int main() {
    char *sieve = (char *)calloc(MAX_PRIME, sizeof(char));
    int squares[MAX_PRIME];
    int i;
    int composite;
    int prime;
    int square;
    int sumFound;
    int answer = 0;
    
    sieve_primes(sieve, MAX_PRIME);

    for (i = 0; i < MAX_SQUARE; i++) {
        squares[i] = i * i;
    }

    for (composite = 9; !answer && composite < MAX_PRIME; composite += 2) {
        if (sieve[composite]) {
            sumFound = 0;

            for (prime = 2; !sumFound && prime < composite && prime < MAX_PRIME; prime++) {
                if (!sieve[prime]) {
                    for (i = 1; !sumFound && squares[i] < composite && i < MAX_SQUARE; i++) {
                        square = squares[i];

                        if (prime + (2 * square) == composite) {
                            sumFound = 1;
                        }
                    }
                }
            }

            if (!sumFound) {
                answer = composite;
            }
        }
    }

    free(sieve);

    printf("%d", answer);
    
    return 0;
}
