/* Problem 115 = 168 */

#include <stdio.h>
#include <stdlib.h>

long long get_placements(int units, int blocks) {
    long long *table = (long long *)calloc(units + 1, sizeof(long long));
    long long placements;
    int i;
    int length;
    int start;
    int block;

    for (i = 0; i < units + 1; i++) {
        table[i] = 1;
    }

    for (length = blocks; length < units + 1; length++) {
        for (block = blocks; block <= length; block++) {
            for (start = 0 ; start <= length - blocks; start++) {
                if (length - block - start >= 0) {
                    ++table[length];
                }

                if (length - block - start - 1 >= blocks) {
                    table[length] += table[length - block - start - 1] - 1;
                }
            }
        }
    }

    placements = table[units];
    free(table);

    return placements;
}

int main() {
    int answer = 0;
    int number = 50;

    while (!answer) {
        if (get_placements(number, 50) > 1000000) {
            answer = number;
        }

        ++number;
    }

    printf("%d", answer);

    return 0;
}
