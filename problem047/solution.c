/* Problem 47 = 134043 */

#include <stdio.h>
#include "../algorithms.h"

#define FACTORS 4

int main() {
    int answer = 0;
    struct list *factors;
    int i;
    int consecutive;
    int number = 1;

    while (!answer) {
        factors = prime_factors(number);

        if (factors->length == FACTORS) {
            consecutive = 1;

            for (i = 1; consecutive && i < FACTORS; i++) {
                list_free(factors);
                factors = prime_factors(number + i);
                consecutive = (factors->length == FACTORS);
            }

            if (consecutive) {
                answer = number;
            }
        }

        list_free(factors);
    
        ++number;
    }

    printf("%d", answer);

    return 0;
}
