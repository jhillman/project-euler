/* Problem 139 = 10057761 */

#include <stdio.h>
#include "../algorithms.h"

#define MAXPERIMETER 100000000

int main() {
    int m = 2;
    int n = 1;
    int a;
    int b;
    int c;
    int k;
    int answer = 0;
    a = 2 * m * n;
    b = m * m - n * n;
    c = m * m + n * n;

    do {
        while (a + b + c <= MAXPERIMETER) {
            if (gcd(m, n) == 1 && (m + n) & 1) {
                answer += ((c % (a - b)) == 0);
                k = 2;

                while (k * a + k * b + k * c <= MAXPERIMETER) {
                    answer += (((k * c) % (k * a - k * b)) == 0);
                    ++k;
                }
            }

            ++m;
            a = 2 * m * n;
            b = m * m - n * n;
            c = m * m + n * n;
        }

        ++n;
        m = n + 1;
        a = 2 * m * n;
        b = m * m - n * n;
        c = m * m + n * n;
    } while (a + b + c <= MAXPERIMETER);

    printf("%d", answer);

    return 0;
}
