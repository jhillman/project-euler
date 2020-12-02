/* Problem 57 = 153 */

#include <stdio.h>
#include "../list_math.h"

int main() {
    struct list *numerator = list_from_number(3);
    struct list *denominator = list_from_number(2);
    struct list *temp;
    char *numeratorString;
    char *denominatorString;
    int i;
    int answer = 0;

    for (i = 1; i < 1000; i++) {
        list_add_list(numerator, denominator);
        temp = numerator;
        numerator = denominator;
        denominator = temp;
        list_add_list(numerator, denominator);
        numeratorString = list_to_string(numerator);
        denominatorString = list_to_string(denominator);
        answer += (strlen(numeratorString) > strlen(denominatorString));
        free(numeratorString);
        free(denominatorString);
    }

    list_free(numerator);
    list_free(denominator);
    
    printf("%d", answer);

    return 0;
}
