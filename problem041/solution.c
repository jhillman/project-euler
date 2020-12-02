/* Problem 41 = 7652413 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../algorithms.h"

int main() {
    char digits[] = "987654321";
    int length = strlen(digits);
    char *digitPtr = digits;
    char pandigital[10];
    int answer = 0;

    while (!answer && length) {
        strcpy(pandigital, digitPtr);

        do {
            if (is_prime(atoi(pandigital))) {
                answer = atoi(pandigital);
            }
        } while (!answer && previous_permutation(pandigital, length));

        ++digitPtr;
        --length;
    }

    printf("%d", answer);
    
    return 0;
}
