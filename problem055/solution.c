/* Problem 55 = 249 */

#include <stdio.h>
#include "../algorithms.h"
#include "../list_math.h"

struct list *reverse_number(struct list *number) {
    char *numberString = list_to_string(number);
    char *digitPtr;
    struct list *reversed;
    reverse_string(numberString);
    digitPtr = numberString;

    while (*digitPtr == '0') {
        ++digitPtr;
    }

    reversed = list_from_string(digitPtr);
    free(numberString);
    
    return reversed;
}

int is_palindrome(struct list *number) {
    struct list *reversed = reverse_number(number);
    int palindrome = (list_compare_list(number, reversed) == 0);
    free(reversed);

    return palindrome;
}

int main() {
    struct list *number;
    struct list *reversed;
    int i;
    int count;
    int answer = 0;

    for (i = 1; i < 10000; i++) {
        number = list_from_number(i);
        count = 0;

        do {
            reversed = reverse_number(number);
            list_add_list(number, reversed);
            list_free(reversed);
            ++count;
        } while (count < 50 && !is_palindrome(number));

        answer += (count == 50);
        list_free(number);
    }

    printf("%d", answer);
    
    return 0;
}
