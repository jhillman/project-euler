/* Problem 30 = 443839 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int power = 5;
    int maximum = (int)pow(9, power) * power;
    int number;
    int sum;
    char numberString[7];
    char *digitPtr;
    int answer = 0;

    for (number = 2; number <= maximum; number++) {
        sum = 0;
        sprintf(numberString, "%d", number);
        digitPtr = numberString + (strlen(numberString) - 1);

        while (digitPtr >= numberString) {
            sum += (int)pow(atoi(digitPtr), power);
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
