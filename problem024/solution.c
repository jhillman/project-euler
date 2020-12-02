/* Problem 24 = 2783915460 */

#include <stdio.h>
#include <string.h>
#include "../algorithms.h"

int main() {
    int number = 1000000;
    int permutations = 1;
    char sequence[] = "0123456789";
    int length = (int)strlen(sequence);

    while (permutations < number) {
        next_permutation(sequence, length);
        ++permutations;
    }

    printf("%s", sequence);
    
    return 0;
}
