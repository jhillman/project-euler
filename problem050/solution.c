/* Problem 50 = 997651 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

#define MAX_PRIME 1000000

int main() {
    char *sieve = (char *)calloc(MAX_PRIME, sizeof(char));
    struct list *primes = list_new();
    struct node *firstPrimeNode;
    struct node *lastPrimeNode;
    long long sum;
    int consecutiveCount;
    int maxConsecutiveCount = 0;
    int i;
    long long answer = 0;

    sieve_primes(sieve, MAX_PRIME);

    for (i = 2; i < MAX_PRIME; i++) {
        if (!sieve[i]) {
            list_push(primes, i);
        }
    }

    firstPrimeNode = lastPrimeNode = primes->first;
    sum = firstPrimeNode->value;
    consecutiveCount = 0;

    while (firstPrimeNode) {
        while (lastPrimeNode->next && sum + lastPrimeNode->next->value < MAX_PRIME) {
            lastPrimeNode = lastPrimeNode->next;
            sum += lastPrimeNode->value;
            ++consecutiveCount;
        }

        while (sieve[sum] && consecutiveCount > 0 && consecutiveCount > maxConsecutiveCount) {
            sum -= lastPrimeNode->value;
            lastPrimeNode = lastPrimeNode->previous;
            --consecutiveCount;
        }

        if (consecutiveCount > maxConsecutiveCount) {
            maxConsecutiveCount = consecutiveCount;
            answer = sum;
        }

        sum -= firstPrimeNode->value;
        --consecutiveCount;
        firstPrimeNode = firstPrimeNode->next;
    }

    list_free(primes);
    free(sieve);
    
    printf("%lld", answer);

    return 0;
}
