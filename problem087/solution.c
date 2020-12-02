/* Problem 87 = 1097343 */

#include <stdio.h>
#include "../algorithms.h"
#include "../list.h"

int main() {
    int max = 50000000;
    int maxPrime = (int)sqrt(max) + 1;
    char *sieve = (char *)calloc(maxPrime, sizeof(char));
    long long poweredPrime;
    struct list *squares = list_new();
    struct list *cubes = list_new();
    struct list *fourthPowers = list_new();
    struct node *square;
    struct node *cube;
    struct node *fourthPower;
    char *sums = (char *)calloc(max, sizeof(char));
    int i;
    int answer = 0;
    sieve_primes(sieve, maxPrime);

    for (i = 2; i * i < max; i++) {
        if (!sieve[i]) {
            poweredPrime = i * i;
            list_push(squares, (int)poweredPrime);

            if ((poweredPrime *= i) < max) {
                list_push(cubes, (int)poweredPrime);
            }

            if ((poweredPrime *= i) < max) {
                list_push(fourthPowers, (int)poweredPrime);
            }
        }
    }

    free(sieve);
    square = squares->first;

    while (square) {
        cube = cubes->first;

        while (cube && square->value + cube->value < max) {
            fourthPower = fourthPowers->first;

            while (fourthPower && square->value + cube->value + fourthPower->value < max) {
                sums[square->value + cube->value + fourthPower->value] = 1;
                fourthPower = fourthPower->next;
            }

            cube = cube->next;
        }

        square = square->next;
    }

    for (i = 0; i < max; i++) {
        answer += sums[i];
    }

    printf("%d", answer);

    list_free(squares);
    list_free(cubes);
    list_free(fourthPowers);
    free(sums);
    
    return 0;
}
