/* Problem 3 = 6857 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    struct list *factors = prime_factors(600851475143LL);

    if (factors->last) {
        printf("%lld", factors->last->value);
    }

    list_free(factors);

    return 0;
}
