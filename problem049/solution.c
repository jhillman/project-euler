/* Problem 49 = 296962999629 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

int compare(const void *a, const void *b) {
    return *((const char *)a) - *((const char *)b);
}

int main() {
    char *sieve = (char *)calloc(10000, sizeof(char));
    char first[5];
    char second[5];
    char third[5];
    int i;
    int j;
    char answer[13];
    sieve_primes(sieve, 10000);

    for (i = 1; i <= 9999; i++) {
        for (j = 1000; j < 10000 - i - i; j++) {
            if (!sieve[j] && !sieve[j + i] && !sieve[j + i + i]) {
                sprintf(first,  "%d", j);
                sprintf(second, "%d", j + i);
                sprintf(third,  "%d", j + i + i);
                qsort(first, 4, sizeof(char), compare);
                qsort(second, 4, sizeof(char), compare);
                qsort(third, 4, sizeof(char), compare);

                if (strcmp(first, second) == 0 && strcmp(first, third) == 0) {
                    sprintf(answer, "%d%d%d", j, j + i, j + i + i);
                }
            }
        }
    }

    free(sieve);

    printf("%s", answer);
    
    return 0;
}
