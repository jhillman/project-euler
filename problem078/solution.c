/* Problem 78 = 55374 */

#include <stdio.h>

int main() {
    int i;
    int j;
    int k;
    int p;
    int partitions;
    int cache[100000] = { 1 };
    int answer = 0;

    for (i = 1; !answer && i < 100000; i++) {
        j = k = 1;
        partitions = 0;

        while (j > 0) {
            p = k * (3 * k + 1) / 2;
            j = i - p;

            if (j >= 0) {
                if (k % 2) {
                    partitions += cache[j];
                } else {
                    partitions -= cache[j];
                }
            }

            j += k;

            if (j >= 0) {
                if (k % 2) {
                    partitions += cache[j];
                } else {
                    partitions -= cache[j];
                }
            }

            k++;
            partitions = partitions % 1000000;
        }

        cache[i] = partitions;

        if (partitions == 0) {
            answer = i;
        }
    }

    printf("%d", answer);

    return 0;
}
