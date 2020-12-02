/* Problem 16 = 1366 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../list_math.h"

int main() {
    int power = 1000;
    struct list *powerList = 0;
    char *numberString;
    char *digitPtr;
    int answer = 0;
    list_power(2, power, &powerList);
    
    digitPtr = numberString = list_to_string(powerList);

    while (*digitPtr) {
        answer += (*digitPtr++ - '0');
    }

    free(numberString);
    list_free(powerList);

    printf("%d", answer);
    
    return 0;
}
