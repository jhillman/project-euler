/* Problem 37 = 748317 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../algorithms.h"

int main() {
    int number = 1000000;
    char *sieve = (char *)calloc(number, sizeof(char));
    char primeString[7];
    char *digitPtr;
    int truncatable;
    int i;
    int answer = 0;
    
    sieve_primes(sieve, number);

    for (i = 11; i < number; i++) {
        if (!sieve[i]) {
            sprintf(primeString, "%d", i);
            truncatable = 1;
            digitPtr = primeString + 1;

            while (truncatable && *digitPtr) {
                truncatable = !sieve[atoi(digitPtr++)];
            }

            if (truncatable) {
                digitPtr = primeString + (int)strlen(primeString) - 2;

                while (truncatable && digitPtr >= primeString) {
                    *(digitPtr-- + 1) = 0;
                    truncatable = !sieve[atoi(primeString)];
                }
            }

            if (truncatable) {
                answer += i;
            }
        }
    }

    free(sieve);

    printf("%d", answer);
    
    return 0;
}
