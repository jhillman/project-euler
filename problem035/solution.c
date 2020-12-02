/* Problem 35 = 55 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../algorithms.h"

int main() {
    int number = 1000000;
    char *sieve = (char *)calloc(number, sizeof(char));
    char primeString[7];
    int length;
    int i;
    int j;
    int k;
    int circular;
    char digit;
    int answer = 0;
    
    sieve_primes(sieve, number);

    for (i = 2; i < number; i++) {
        if (!sieve[i]) {
            sprintf(primeString, "%d", i);
            length = (int)strlen(primeString);
            circular = !sieve[atoi(primeString)];

            for (j = 1; circular && j < length; j++) {
                digit = *primeString;

                for (k = 1; k < length; k++) {
                    primeString[k - 1] = primeString[k];
                }

                primeString[length - 1] = digit;
                circular = !sieve[atoi(primeString)];
            }

            if (circular) {
                ++answer;
            }
        }
    }

    free(sieve);

    printf("%d", answer);
    
    return 0;
}
