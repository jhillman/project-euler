/* Problem 188 = 95962097 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    int a = 1777;
    int b = 1855;
    int answer = 1;

    while (b) {
        answer = (int)modulus_power(a, answer, 100000000);
        --b;
    }

    printf("%d", answer);

    return 0;
}
