/* Problem 77 = 71 */

#include <stdio.h>
#include "../list.h"
#include "../algorithms.h"

int main() {
    struct list *allPrimes = list_new();
    struct list *primes = 0;
    char *sieve = 0;
    int n;
    int answer = 0;
    sieve = (char *)calloc(100, sizeof(char));
    sieve_primes(sieve, 100);

    for (n = 2; n < 100; n++) {
        if (!sieve[n]) {
            list_push(allPrimes, n);
        }
    }

    n = 2;

    while (!answer) {
        primes = list_copy(allPrimes);

        if (get_combinations(n, primes) > 5000) {
            answer = n;
        }

        list_free(primes);
        ++n;
    }

    printf("%d", answer);

    list_free(allPrimes);
    free(sieve);

    return 0;
}
