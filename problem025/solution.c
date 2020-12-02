/* Problem 25 = 4782 */

#include <stdio.h>
#include <math.h>
#include "../list_math.h"
#include "../algorithms.h"

int main() {
    struct list *first = list_from_number(1);
    struct list *second = list_from_number(1);
    struct list *current = 0;
    struct list *temp;
    int term = 2;
    int maxSegments;
    int maxSegmentDigits;

    if (1000 % LIST_NUMBER_LENGTH) {
        maxSegments = (int)(1000 / LIST_NUMBER_LENGTH) + 1;
        maxSegmentDigits = 1000 % LIST_NUMBER_LENGTH;
    } else {
        maxSegments = 1000 / LIST_NUMBER_LENGTH;
        maxSegmentDigits = LIST_NUMBER_LENGTH;
    }

    do {
        list_free(current);
        current = list_copy(first);
        list_add_list(current, second);

        if (current->length != maxSegments || count_digits(current->first->value) < maxSegmentDigits) {
            temp = first;
            first = second;
            second = current;
            current = temp;
        }

        ++term;
    } while (current->length != maxSegments || count_digits(current->first->value) < maxSegmentDigits);

    list_free(first);
    list_free(second);
    list_free(current);

    printf("%d", term);
    
    return 0;
}
