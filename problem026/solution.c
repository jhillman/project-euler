/* Problem 26 = 983 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

int main() {
    int maximum = 1000;
    char *sieve = (char *)calloc(maximum, sizeof(char));
    int denominator;
    int answer = 0;
    int maxDigits = 0;
    int digit;
    int digits;
    int remainder;
    int i;
    sieve_primes(sieve, maximum);

    for (i = 2; i < maximum; i++) {
        if (!sieve[i]) {
            denominator = i;
            digits = 0;
            remainder = 1;

            do {
                while (remainder < denominator) {
                    remainder *= 10;
                }

                digit = (int)(remainder / denominator);
                remainder = remainder - (digit * denominator);
                ++digits;
            } while (remainder > 1 && digits < 1000);

            if (remainder == 1) {
                if (digits > maxDigits) {
                    answer = denominator;
                    maxDigits = digits;
                }
            }
        }
    }

    free(sieve);

    printf("%d", answer);
    
    return 0;
}
