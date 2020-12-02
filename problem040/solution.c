/* Problem 40 = 210 */

#include <stdio.h>

int main() {
    char digits[1000020];
    char *digitPtr;
    int integer = 1;
    int answer;
    digitPtr = digits + 1;

    while (digitPtr - digits < 1000010) {
        digitPtr += sprintf(digitPtr, "%d", integer++);
    }

    answer = (*(digits + 1) - '1' + 1) *
             (*(digits + 10) - '1' + 1) *
             (*(digits + 100) - '1' + 1) *
             (*(digits + 1000) - '1' + 1) *
             (*(digits + 10000) - '1' + 1) *
             (*(digits + 100000) - '1' + 1) *
             (*(digits + 1000000) - '1' + 1);

    printf("%d", answer);
    
    return 0;
}
