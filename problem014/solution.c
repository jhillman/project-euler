/* Problem 14 = 837799 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main() {
    int answer = 0;
    int max = 0;
    int *termHash = (int *)calloc(MAX, sizeof(int));
    long long number;
    int terms;
    int i;

    for (i = 2; i < MAX; i++) {
        number = i;
        terms = 1;

        while (number != 1) {
            if (number & 1) {
                number = (3 * number) + 1;
            } else {
                number /= 2;
            }

            terms++;

            if (number < MAX && termHash[number]) {
                terms += termHash[number];
                number = 1;
            }
        }

        termHash[i] = terms;

        if (terms > max) {
            answer = i;
            max = terms;
        }
    }

    free(termHash);
    
    printf("%d", answer);

    return 0;
}
