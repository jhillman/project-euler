/* Problem 138 = 1118049290473932 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 12;
    long long *fibonacci = (long long*)calloc((6 * count + 3) + 1, sizeof(long long));
    int n;
    long long answer = 0;
    fibonacci[1] = fibonacci[2] = 1;

    for (n = 3; n <= 6 * count + 3; n++) {
        fibonacci[n] = fibonacci[n - 1] + fibonacci[n - 2];
    }

    for (n = 1; n <= count; n++) {
        answer += fibonacci[6 * n + 3] / 2;
    }

    free(fibonacci);

    printf("%lld", answer);

    return 0;
}
