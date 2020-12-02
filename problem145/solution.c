/* Problem 145 = 608720 */

#include <stdio.h>

int main() {
    int n;
    int sum;
    int reverse_n;
    int reversible;
    int answer = 0;

    for (n = 1; n <= 100000000; n += 2) {
        if (n % 10) {
            sum = n;
            reverse_n = 0;

            while (n) {
                reverse_n *= 10;
                reverse_n += n % 10;
                n /= 10;
            }

            n = sum;

            if ((n % 10 & 1) ^ (reverse_n % 10 & 1)) {
                sum += reverse_n;
                reversible = 1;

                while (sum && reversible) {
                    reversible = ((sum % 10) & 1);
                    sum /= 10;
                }

                answer += reversible * 2;
            }
        }
    }

    printf("%d", answer);

    return 0;
}
