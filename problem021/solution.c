/* Problem 21 = 31626 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 10000;
    int *sums = (int *)calloc(number, sizeof(int));
    int factor;
    int divisor;
    int sum;
    int answer = 0;
    int i;

    for (i = 1; i <= number; i++) {
        factor = 2;
        divisor = i * factor;

        while (divisor < number) {
            sums[divisor] = i + sums[divisor];
            divisor = i * ++factor;
        }
    }

    for (i = 2; i < number; i++) {
        sum = sums[i];

        if (sum < number && sum != i) {
            if (sums[sum] && i == sums[sum]) {
                answer += i;
            }
        }
    }

    free(sums);

    printf("%d", answer);
    
    return 0;
}
