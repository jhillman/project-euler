/* Problem 70 = 8319823 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

int compare(const void *a, const void *b) {
    return *((const char *)a) - *((const char *)b);
}

int main() {
    int squareRoot = (int)sqrt(10000000);
    int minimumPrime = squareRoot / 2;
    int maximumPrime = squareRoot * 2;
    char *sieve = (char *)calloc(maximumPrime, sizeof(char));
    struct list *primes = list_new();
    struct node *prime1;
    struct node *prime2;
    long long n;
    double totient;
    int digits;
    char nString[9];
    char totientString[9];
    double ratio;
    double minimum = 10000000;
    long long answer = 0;
    sieve_primes(sieve, maximumPrime);

    for (n = minimumPrime; n < maximumPrime; n++) {
        if (!sieve[n]) {
            list_push(primes, n);
        }
    }

    prime1 = primes->first;

    while (prime1) {
        prime2 = prime1->next;

        while (prime2) {
            n = prime1->value * prime2->value;

            if (n < 10000000) {
                totient = (double)((prime1->value - 1) * (prime2->value - 1));
                digits = count_digits(n);

                if (digits == count_digits((long long)totient)) {
                    sprintf(nString, "%lld", n);
                    qsort(nString, digits, sizeof(char), compare);
                    sprintf(totientString, "%d", (int)totient);
                    qsort(totientString, digits, sizeof(char), compare);

                    if (strcmp(nString, totientString) == 0) {
                        ratio = (double)n / totient;

                        if (ratio < minimum) {
                            minimum = ratio;
                            answer = n;
                        }
                    }
                }
            }

            prime2 = prime2->next;
        }

        prime1 = prime1->next;
    }

    free(sieve);
    list_free(primes);

    printf("%lld", answer);
    
    return 0;
}
