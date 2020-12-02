/* Problem 128 = 14516824220 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    long long number;
    long long ring = 2;
    int spoke;
    long long tileOne = 0;
    long long tileTwo = 0;
    long long tileThree = 0;
    int pd3Count = 2; /* tiles 1 and 2 */
    long long answer = 0;

    while (!answer) {
        number = 3 * ring * (ring - 1) + 2;

        for (spoke = 0; spoke <= 1; spoke++) {
            switch (spoke) {
            case 0:
                tileOne = 6 * ring + 1;
                tileTwo = tileOne - 2;
                tileThree = 12 * ring + 5;
                break;

            case 1:
                number += 6 * ring - 1;
                tileOne = 6 * ring - 1;
                tileTwo = 12 * ring - 7;
                tileThree = 6 * ring + 5;
                break;
            }

            if (is_prime(tileOne) && is_prime(tileTwo) && is_prime(tileThree)) {
                if (++pd3Count == 2000) {
                    answer = number;
                }
            }
        }

        ++ring;
    }

    printf("%lld", answer);

    return 0;
}
