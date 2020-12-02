/* Problem 205 = 0.5731441 */

#include <stdio.h>
#include <stdlib.h>

void roll_dice(int sides, int dice, int sum, int *sums) {
    int i;

    if (dice == 0) {
        ++sums[sum];
    } else {
        for (i = 1; i <= sides; i++) {
            roll_dice(sides, dice - 1, sum + i, sums);
        }
    }
}

int main() {
    int *peterSums = (int *)calloc(37, sizeof(int));
    int *colinSums = (int *)calloc(37, sizeof(int));
    long long rolls = 0;
    long long wins = 0;
    int i;
    int j;
    double answer = 0;
    roll_dice(4, 9, 0, peterSums);
    roll_dice(6, 6, 0, colinSums);

    for (i = 1; i <= 36; i++) {
        for (j = 1; j < i; j++) {
            wins += peterSums[i] * colinSums[j];
        }

        for (j = 1; j <= 36; j++) {
            rolls += peterSums[i] * colinSums[j];
        }
    }

    answer = (double)wins / (double)rolls;
    free(peterSums);
    free(colinSums);

    printf("%.7f", answer);

    return 0;
}

