/* Problem 131 = 173 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    char *sieve = (char *)calloc(1000000, sizeof(char));
    int n;
    int p;
    int answer = 0;

    sieve_primes(sieve, 1000000);

    n = 1;
    p = 3 * n * n + 3 * n + 1;

    while (p < 1000000) {
        answer += !sieve[p];
        ++n;
        p = 3 * n * n + 3 * n + 1;
    }

    free(sieve);

    printf("%d", answer);

    return 0;
}
