/* Problem 135 = 4989 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int maximum = 1000000;
    int x;
    int k;
    int solution;
    int *solutions = (int *)calloc(maximum, sizeof(int));
    int answer = 0;

    /*
    x = x
    y = x + k
    z = x + 2k

    z^2 - y^2 - x^2 = (x + 2k)^2 - (x + k)^2 - x^2

    (x + 2k)^2 - (x + k)^2 - x^2 = 3 * k^2 + 2 * x * k - x^2
    */

    for (x = 1; x < maximum; x++) {
        for (k = (x + 2) / 3; k < maximum; k++) {
            solution = 3 * k * k + 2 * x * k - x * x;

            if (solution > 0 && solution < maximum) {
                ++solutions[solution];
            } else if (solution > maximum) {
                break;
            }
        }
    }

    for (solution = 0; solution < maximum; solution++) {
        if (solutions[solution] == 10) {
            ++answer;
        }
    }

    free(solutions);

    printf("%d", answer);

    return 0;
}
