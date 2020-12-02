/* Problem 6 = 25164150 */

#include <stdio.h>
#include <math.h>

int main() {
    int number = 100;
    int sumOfTheSquare = 0;
    int squareOfTheSum;
    int i;

    for (i = 1; i <= number; i++) {
        sumOfTheSquare += i * i;
    }

    squareOfTheSum = (int)pow(((number * (1 + number)) / 2), 2);

    printf("%d", (squareOfTheSum - sumOfTheSquare));

    return 0;
}
