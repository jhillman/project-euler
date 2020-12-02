/* Problem 71 = 428570 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    int n = 1000000;
    double numerator;
    int denominator = n - 1;
    int answer = 0;

    /* http://en.wikipedia.org/wiki/Farey_sequence */

    do {
        numerator = ((3 * denominator) - 1) / 7;

        if (numerator == (int)numerator && gcd((int)numerator, denominator) == 1) {
            answer = (int)numerator;
        }

        --denominator;
    } while (!answer);

    printf("%d", answer);
    
    return 0;
}
