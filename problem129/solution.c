/* Problem 129 = 1000023 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    int n = 1000000;
    int k;
    int divisor;
    int answer = 0;

    while (!answer) {
        if (gcd(10, n) == 1) {
            k = 1;
            divisor = n * 9;

            while (modulus_power(10, k, divisor) != 1) {
                ++k;
            }

            if (k > 1000000) {
                answer = n;
            }
        }

        ++n;
    }

    printf("%d", answer);

    return 0;
}
