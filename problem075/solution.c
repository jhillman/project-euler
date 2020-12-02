/* Problem 75 = 214954 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

#define MAXLENGTH 2000000

int main() {
    int m = 2;
    int n = 1;
    int a;
    int b;
    int c;
    int k;
    int *lengths = (int *)calloc(MAXLENGTH + 1, sizeof(int));
    int i;
    int answer = 0;
    a = 2 * m * n;
    b = m * m - n * n;
    c = m * m + n * n;

    do {
        while (a + b + c <= MAXLENGTH) {
            if (gcd(m, n) == 1 && (m + n) & 1) {
                ++lengths[a + b + c];
                k = 2;

                while (k * a + k * b + k * c <= MAXLENGTH) {
                    ++lengths[k * a + k * b + k * c];
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
    } while (a + b + c <= MAXLENGTH);

    for (i = 12; i <= MAXLENGTH; i++) {
        answer += (lengths[i] == 1);
    }

    free(lengths);
    
    printf("%d", answer);
    
    return 0;
}
