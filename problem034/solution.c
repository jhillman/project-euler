/* Problem 34 = 40730 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int factorials[10] = { 1 };
    int number;
    int sum;
    char numberString[7];
    char *digitPtr;
    int answer = 0;

    for (number = 1; number < 10; number++) {
        factorials[number] = number * factorials[number - 1];
    }

    for (number = 3; number < factorials[9]; number++) {
        sum = 0;
        sprintf(numberString, "%d", number);
        digitPtr = numberString + (strlen(numberString) - 1);

        while (digitPtr >= numberString) {
            sum += factorials[atoi(digitPtr)];
            digitPtr--;
            *(digitPtr + 1) = 0;
        }

        if (sum == number) {
            answer += number;
        }
    }

    printf("%d", answer);
    
    return 0;
}
