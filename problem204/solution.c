/* Problem 204 = 2944730 */

#include <stdio.h>
#include "../algorithms.h"
#include "../list.h"

long long count_hammings(long long hamming, struct node *prime, int maximum) {
    long long hammings = 0;

    while (hamming <= maximum) {
        if (prime->next) {
            hammings += count_hammings(hamming, prime->next, maximum);
        }

        hamming *= (int)prime->value;

        if (hamming <= maximum) {
            ++hammings;
        }
    }

    return hammings;
}

int main() {
    int maximum = 1000000000;
    char *sieve = (char *)calloc(100, sizeof(char));
    struct list *primes = list_new();
    int prime;
    long long answer = 0;

    sieve_primes(sieve, 100);

    for (prime = 2; prime < 100; prime++) {
        if (!sieve[prime]) {
            list_push(primes, prime);
        }
    }

    answer = count_hammings(1, primes->first, maximum) + 1;
    free(sieve);
    list_free(primes);

    printf("%lld", answer);

    return 0;
}
