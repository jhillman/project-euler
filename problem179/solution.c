/* Problem 179 = 986262 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int maximum = 10000000;
    int *divisors = (int *)calloc(maximum + 1, sizeof(int));
    int i;
    int j;
    int answer = 0;

    for (i = 2; i <= maximum; i++) {
        for (j = i; j <= maximum; j += i) {
            divisors[j] += 1;
        }
    }

    for (i = 1; i < maximum; i++) {
        answer += (divisors[i] == divisors[i + 1]);
    }

    free(divisors);

    printf("%d", answer);

    return 0;
}
