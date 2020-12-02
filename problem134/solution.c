/* Problem 134 = 18613426663617118 */

#include <stdio.h>
#include "../algorithms.h"

long long s(int p1, int p2) {
    int magnitude = (int)pow(10, count_digits(p1));
    long long number = ((p2 - p1) * modulus_power(magnitude % p2, p2 - 2, p2)) % p2;

    return number * magnitude + p1;
}

int main() {
    char *sieve = (char *)calloc(1000005, sizeof(char));
    int p1;
    int p2;
    long long answer = 0;
    sieve_primes(sieve, 1000005);
    p1 = 5;

    do {
        p2 = p1 + 1;

        while (sieve[p2]) {
            ++p2;
        }

        answer += s(p1, p2);
        p1 = p2;
    } while (p1 < 1000000);

    free(sieve);

    printf("%lld", answer);

    return 0;
}
