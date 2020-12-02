/* Problem 56 = 972 */

#include <stdio.h>
#include "../list_math.h"

int main() {
    int number;
    int power;
    char *numberString;
    char *digitPtr;
    struct list *powerList = 0;
    int sum;
    int answer = 0;

    for (number = 1; number < 100; number++) {
        for (power = 1; power < 100; power++) {
            list_power(number, power, &powerList);
            sum = 0;
            digitPtr = numberString = list_to_string(powerList);

            while (*digitPtr) {
                sum += (*digitPtr++ - '0');
            }

            if (sum > answer) {
                answer = sum;
            }

            free(numberString);
            list_free(powerList);
        }
    }

    printf("%d", answer);
    
    return 0;
}

