/* Problem 38 = 932718654 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../algorithms.h"

int main() {
    char pandigital[] = "987654321";
    int possibleNs[9876 + 1];
    int digit1;
    int digit2;
    int digit3;
    int digit4;
    int length = (int)strlen(pandigital);
    int n;
    int i;
    char product[100];
    char *pandigitalPtr;
    int productLength;
    int answer = 0;

    for (i = 9000; i <= 9876; i++) {
        n = i;
        digit4 = n % 10;
        n -= digit4;
        digit3 = n % 100;
        n -= digit3;
        digit2 = n % 1000;
        n -= digit2;
        digit1 = n / 1000;

        if (digit1 && digit2 && digit3 && digit4 &&
                digit1 != digit2 && digit1 != digit3 && digit1 != digit4 &&
                digit2 != digit3 && digit2 != digit4 &&
                digit3 != digit4) {
            possibleNs[i] = 1;
        } else {
            possibleNs[i] = 0;
        }
    }

    while (!answer) {
        for (n = 9876; n >= 9000; n--) {
            if (possibleNs[n]) {
                pandigitalPtr = pandigital;
                productLength = 0;
                integer_to_ascii(n, product, 10);
                productLength = (int)strlen(product);

                if (strncmp(pandigitalPtr, product, productLength) == 0) {
                    pandigitalPtr += productLength;
                    integer_to_ascii(n * 2, product, 10);
                    productLength = (int)strlen(product);

                    if (strncmp(pandigitalPtr, product, productLength) == 0) {
                        answer = atoi(pandigital);
                        break;
                    }
                }
            }
        }

        previous_permutation(pandigital, length);
    }

    printf("%d", answer);
    
    return 0;
}
