/* Problem 112 = 1587000 */

#include <stdio.h>

int is_bouncy(int number) {
    int bouncy = 0;
    int down = 0;
    int up = 0;
    int digit;
    int lastDigit = number % 10;
    number /= 10;

    while (!bouncy && number) {
        digit = number % 10;

        if (digit > lastDigit) {
            down = 1;
        } else if (digit < lastDigit) {
            up = 1;
        }

        bouncy = (up && down);
        lastDigit = digit;
        number /= 10;
    }

    return bouncy;
}

int main() {
    int bouncy = 0;
    int number = 100;
    int answer = 0;

    while (!answer) {
        bouncy += is_bouncy(number);

        if (bouncy * 100 / number == 99) {
            answer = number;
        }

        ++number;
    }

    printf("%d", answer);

    return 0;
}
