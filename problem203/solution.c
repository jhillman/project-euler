/* Problem 203 = 34029210557338 */

#include <stdio.h>
#include "../list.h"
#include "../algorithms.h"

#define ROWS 51

int main() {
    int i;
    int j;
    long long sum;
    long long triangle[ROWS][ROWS];
    struct list *unique = list_new();
    char *sieve = (char *)calloc(12000000, sizeof(char));
    long long n;
    int squareRoot;
    int squareFree;
    long long answer = 0;

    sieve_primes(sieve, 12000000);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < ROWS; j++) {
            triangle[i][j] = 0;
        }
    }

    triangle[0][0] = 1;

    for (i = 1; i < ROWS; i++) {
        for (j = 0; j <= i; j++) {
            sum = triangle[i - 1][j];

            if (j > 0) {
                sum += triangle[i - 1][j - 1];
            }

            triangle[i][j] = sum;

            if (!list_find(unique, sum)) {
                list_push(unique, sum);
                squareRoot = (int)sqrt((double)sum);
                squareFree = 1;

                for (n = 2; n <= squareRoot && squareFree; n++) {
                    if (!sieve[n]) {
                        squareFree = (int)(sum % (n * n));
                    }
                }

                if (squareFree) {
                    answer += sum;
                }
            }
        }
    }

    list_free(unique);
    free(sieve);

    printf("%lld", answer);

    return 0;
}
