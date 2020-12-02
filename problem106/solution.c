/* Problem 106 = 21384 */

#include <stdio.h>

int factorial(int number) {
    int result = 1;

    if (number > 1) {
        result = number * factorial(number - 1);
    }

    return result;
}

int choose(int number, int chosen) {
    return factorial(number) / (factorial(chosen) * factorial(number - chosen));
}

int main() {
    int number = 12;
    int size;
    int answer = 0;

    for (size = 2; size < number / 2 + 1; size++) {
        answer += choose(number, 2 * size) * choose(2 * size - 1, size + 1);
    }

    printf("%d", answer);

    return 0;
}
