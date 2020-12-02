/* Problem 94 = 518408346 */

#include <stdio.h>
#include <math.h>

int main() {
    int side;
    int sidePlusOrMinusOne;
    int x;
    double sqrt3 = sqrt(3);
    int perimeter;
    int triangle = 1;
    int answer = 0;

    /* Pell equation: x^2 ? 3y^2 = 1 */

    do {
        ++triangle;
        x = (int)ceil((pow(2 + sqrt3, triangle) + pow(2 - sqrt3, triangle)) / 2);

        if ((int)(2 * x + 1) % 3 == 0) {
            side = (2 * x + 1) / 3;
            sidePlusOrMinusOne = side + 1;
        } else {
            side = (2 * x - 1) / 3;
            sidePlusOrMinusOne = side - 1;
        }

        perimeter = 2 * side + sidePlusOrMinusOne;

        if (perimeter <= 1000000000) {
            answer += perimeter;
        }
    } while (perimeter <= 1000000000);

    printf("%d", answer);
}
