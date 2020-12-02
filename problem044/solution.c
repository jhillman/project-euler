/* Problem 44 = 5482660 */

#include <stdio.h>
#include <math.h>

int is_pentagonal(int pentagonal) {
    double n = (sqrt(24 * pentagonal + 1) + 1) / 6;
    return (n == (int)n);
}

int main() {
    int k;
    int j;
    int difference;
    int sum;
    int answer = 0;
    k = 1;

    while (!answer) {
        j = 1;

        do {
            difference = ((k * (3 * k - 1)) / 2) -
                         ((j * (3 * j - 1)) / 2);

            if (is_pentagonal(difference)) {
                sum = ((k * (3 * k - 1)) / 2) +
                      ((j * (3 * j - 1)) / 2);

                if (is_pentagonal(sum)) {
                    answer = difference;
                }
            }

            ++j;
        } while (!answer && j < k);

        ++k;
    }

    printf("%d", answer);
    
    return 0;
}
