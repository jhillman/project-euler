/* Problem 124 = 21417 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"
#include "../list_math.h"

struct radical_info {
    int n;
    int radical;
};

int compare_radical_info(const void *a, const void *b) {
    int result = (*(struct radical_info *)a).radical - (*(struct radical_info *)b).radical;

    if (result == 0) {
        result = (*(struct radical_info *)a).n - (*(struct radical_info *)b).n;
    }

    return result;
}

int main() {
    struct list *factors;
    struct radical_info e[100001] = { 0, 0 };
    int n;
    int answer = 0;

    for (n = 1; n <= 100000; n++) {
        factors = prime_factors(n);
        e[n].n = n;
        e[n].radical = (int)list_product(factors);
        list_free(factors);
    }

    qsort(e, 100001, sizeof(struct radical_info), compare_radical_info);
    answer = e[10000].n;

    printf("%d", answer);

    return 0;
}
