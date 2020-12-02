/* Problem 104 = 329468 */

#include <stdio.h>
#include <stdlib.h>

int is_pandigital(long long number) {
    int digit;
    int *digitCounts = (int *)calloc(10, sizeof(int));
    int pandigital = 1;

    while (number) {
        ++digitCounts[number % 10];
        number /= 10;
    }

    for (digit = 1; pandigital && digit < 10; digit++) {
        if (digitCounts[digit] > 1) {
            pandigital = 0;
        } else {
            pandigital = digitCounts[digit];
        }
    }

    free(digitCounts);

    return pandigital;
}

int main() {
    const unsigned long long maximum = ~((unsigned long long)0);
    unsigned long long most1 = 1;
    unsigned long long most2 = 1;
    unsigned long long least1 = 1;
    unsigned long long least2 = 1;
    unsigned long long most;
    unsigned long long least;
    int term = 3;
    int answer = 0;

    while (!answer) {
        most = most1 + most2;
        least = least1 + least2;

        if (least >= 1000000000) {
            least %= 1000000000;
            least2 %= 1000000000;
        }

        least1 = least2;
        least2 = least;

        if (most >= maximum / 10) {
            most /= 10;
            most2 /= 10;
        }

        most1 = most2;
        most2 = most;

        while (most > 1000000000) {
            most /= 10;
        }

        if (is_pandigital(most) && is_pandigital(least)) {
            answer = term;
        }

        ++term;
    }

    printf("%d", answer);

    return 0;
}
