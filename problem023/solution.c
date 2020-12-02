/* Problem 23 = 4179871 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int maximum = 28123;
    int *sums = (int *)calloc(maximum, sizeof(int));
    int *abundants = (int *)calloc(maximum, sizeof(int));
    int factor;
    int divisor;
    int answer = 0;
    int add;
    int i;
    int j;

    for (i = 1; i <= maximum; i++) {
        factor = 2;
        divisor = i * factor;

        while (divisor < maximum) {
            sums[divisor] = i + sums[divisor];
            divisor = i * ++factor;
        }
    }

    for (i = 2; i < maximum; i++) {
        if (sums[i] > i) {
            abundants[i] = 1;
        }
    }

    for (i = 1; i <= maximum; i++) {
        add = 1;

        for (j = 1; add && j < i; j++) {
            if (abundants[j] && abundants[i - j]) {
                add = 0;
            }
        }

        if (add) {
            answer += i;
        }
    }

    free(sums);
    free(abundants);
    
    printf("%d", answer);

    return 0;
}
