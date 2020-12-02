/* Problem 20 = 648 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../list_math.h"

int main() {
    int number = 100;
    struct list *factorial = 0;
    char *numberString;
    char *digitPtr;
    int answer = 0;
    
    list_factorial(number, &factorial);
    digitPtr = numberString = list_to_string(factorial);

    while (*digitPtr) {
        answer += (*digitPtr++ - '0');
    }

    free(numberString);
    list_free(factorial);

    printf("%d", answer);
    
    return 0;
}

