/* Problem 10 = 142913828922 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../algorithms.h"

int main() {
    int number = 2000000;
    char *sieve = (char *)calloc(number, sizeof(char));
    long long answer = 0;
    int i;

    sieve_primes(sieve, number);

    for (i = 2; i < number; i++) {
        if (!sieve[i]) {
            answer += i;
        }
    }

    free(sieve);

    printf("%lld", answer);

    return 0;
}
