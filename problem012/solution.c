/* Problem 12 = 76576500 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    int number = 500;
    int trial = number;
    int triangle;
    struct list *factors;
    struct node *factor;
    int divisors;
    int power;
    long long product;
    int answer = 0;
    int found = 0;

    while (!found) {
        triangle = (trial * (trial + 1)) / 2;
        factors = prime_factors(triangle);
        /* divisor function */
        /* http://en.wikipedia.org/wiki/Divisor_function */
        divisors = 1;
        factor = factors->first;

        while (factor) {
            power = 1;
            product = factor->value * factor->value;

            while (triangle % product == 0) {
                ++power;
                product *= factor->value;
            }

            divisors *= (power + 1);
            factor = factor->next;
        }

        list_free(factors);

        if (divisors > number) {
            answer = triangle;
            found = 1;
        }

        ++trial;
    }

    printf("%d", answer);
    
    return 0;
}
