/* Problem 29 = 9183 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../list_math.h"

int main() {
    int maxExponent = 100;
    struct list *uniques[10000];
    struct list *number;
    int a;
    int b;
    int i;
    int unique;
    int uniqueCount = 0;

    for (a = 2; a <= maxExponent; a++) {
        for (b = 2; b <= maxExponent; b++) {
            list_power(a, b, &number);
            unique = 1;

            for (i = 0; unique && i < uniqueCount; i++) {
                unique = (list_compare_list(number, uniques[i]) != 0);
            }

            if (unique) {
                uniques[uniqueCount++] = number;
            } else {
                list_free(number);
            }
        }
    }

    for (i = 0; i < uniqueCount; i++) {
        list_free(uniques[i]);
    }

    printf("%d", uniqueCount);
    
    return 0;
}
