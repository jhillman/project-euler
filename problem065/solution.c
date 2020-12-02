/* Problem 65 = 272 */

#include <stdio.h>
#include "../list_math.h"

void add_convergent(int n, int limit, struct list **numerator, struct list **denominator) {
    int number = 1;
    struct list *localNumerator = 0;
    struct list *localDenominator = 0;

    if (n == 0) {
        number = 2;
    } else if (n % 3 == 2) {
        number = 2 * ((n / 3) + 1);
    }

    if (n == limit - 1) {
        *numerator = list_from_number(1);
        *denominator = list_from_number(number);
    } else {
        add_convergent(n + 1, limit, &localNumerator, &localDenominator);
        *numerator = localDenominator;
        *denominator = list_copy(localDenominator);
        list_multiply_number(*denominator, number);
        list_add_list(*denominator, localNumerator);
        list_free(localNumerator);
    }

    if (n == 0) {
        localNumerator = *denominator;
        *denominator = *numerator;
        *numerator = localNumerator;
    }
}

int main() {
    struct list *numerator = 0;
    struct list *denominator = 0;
    char *numeratorString;
    char *digitPtr;
    int answer = 0;
    add_convergent(0, 100, &numerator, &denominator);
    digitPtr = numeratorString = list_to_string(numerator);

    while (*digitPtr) {
        answer += (*(digitPtr++) - '0');
    }

    free(numeratorString);
    list_free(numerator);
    list_free(denominator);
    
    printf("%d", answer);

    return 0;
}
