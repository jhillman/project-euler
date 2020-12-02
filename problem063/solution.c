/* Problem 63 = 49 */

#include <stdio.h>
#include "../list_math.h"

int main() {
    struct list *powerList = 0;
    char *numberString;
    int number;
    int power = 1;
    int digits;
    int count;
    int answer = 0;

    do {
        number = 1;
        count = 0;

        do {
            list_power(number, power, &powerList);
            numberString = list_to_string(powerList);
            digits = strlen(numberString);

            if (digits == power) {
                ++count;
            }

            free(numberString);
            list_free(powerList);
            ++number;
        } while (digits <= power);

        answer += count;
        ++power;
    } while (count > 0);

    printf("%d", answer);
    
    return 0;
}
