/* Problem 32 = 45228 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../algorithms.h"

int main() {
    char sequence[] = "123456789";
    int length = (int)strlen(sequence);
    char pandigital[10];
    char *productPtr;
    char *multiplierPtr;
    int multiplierOffset;
    char multiplierDigit;
    int product;
    int multiplier;
    int multiplicand;
    int *products = (int *)calloc(10000, sizeof(int));
    int answer = 0;

    do {
        strcpy(pandigital, sequence);
        productPtr = pandigital + 5;
        product = atoi(productPtr);
        *productPtr = 0;

        /* try multipliers that are one, two, or three digits */
        for (multiplierOffset = 3; multiplierOffset >= 1; multiplierOffset--) {
            multiplierPtr = pandigital + multiplierOffset;
            multiplier = atoi(multiplierPtr);
            multiplierDigit = *multiplierPtr;
            *multiplierPtr = 0;
            multiplicand = atoi(pandigital);
            *multiplierPtr = multiplierDigit;

            if (product % multiplier == 0 && product / multiplier == multiplicand) {
                if (!products[product]) {
                    answer += product;
                    products[product] = 1;
                }
            }
        }
    } while (next_permutation(sequence, length));

    free(products);

    printf("%d", answer);
    
    return 0;
}
