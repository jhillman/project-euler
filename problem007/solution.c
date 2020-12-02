/* Problem 7 = 104743 */

#include <stdio.h>
#include <math.h>
#include "../list.h"

int main() {
    int number = 10001;
    struct list *primes = list_new();
    struct node *prime;
    int trial = 1;
    double squareRoot;

    list_push(primes, 2);

    while (primes->length < number) {
        trial += 2;
        squareRoot = sqrt(trial);
        prime = primes->first;

        while (prime) {
            if (prime->value > squareRoot) {
                list_push(primes, trial);
                break;
            }

            if (trial % prime->value == 0) {
                break;
            }

            prime = prime->next;
        }
    }

    if (primes->last) {
        printf("%lld", primes->last->value);
    }

    list_free(primes);

    return 0;
}
