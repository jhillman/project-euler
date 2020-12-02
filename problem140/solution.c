/* Problem 140 = 5673835352990 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 30;
    long long *fibonacci = (long long*)calloc(count * 2 + 2, sizeof(long long));
    int n;
    int f;
    long long term;
    long long answer = 0;
    fibonacci[1] = fibonacci[2] = 1;

    for (n = 3; n <= count * 2 + 1; n++) {
        fibonacci[n] = fibonacci[n - 1] + fibonacci[n - 2];
    }

    for (n = 1; n <= count; n++) {
        term = 2;

        for (f = 4; f <= 2 * n; f += 4) {
            term += fibonacci[f];
        }

        for (f = 6; f <= 2 * n; f += 4) {
            term += fibonacci[f] * 2;
        }

        answer += term;
    }

    free(fibonacci);

    printf("%lld", answer);

    return 0;
}

