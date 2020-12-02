/* Problem 5 = 232792560 */

#include <stdio.h>
#include <math.h>

int main() {
    int number = 20;
    int numbers[] = { -1, -1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 0 };
    int power;
    int *numberPtr;
    int prime;
    int product;
    int answer = 1;

    while (1) {
        numberPtr = numbers;

        while (*numberPtr < 0) {
            ++numberPtr;
        }

        prime = *numberPtr;

        if (prime == 0) {
            break;
        }

        power = 1;
        product = prime * prime;

        while (product < number) {
            numbers[product] = -1;
            product *= prime;
            ++power;
        }

        answer *= (int)pow(prime, power);
        numberPtr = numbers;

        while (*numberPtr) {
            if (*numberPtr % prime == 0) {
                *numberPtr = -1;
            }

            ++numberPtr;
        }
    }

    printf("%d", answer);

    return 0;
}
