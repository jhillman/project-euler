/* Problem 120 = 333082500 */

#include <stdio.h>
#include <stdlib.h>
#include "../list_math.h"
#include "../algorithms.h"

#ifdef max
#undef max
#endif
#define max(x, y) ((x) > (y) ? (x) : (y))

int main() {
    int a;
    int n;
    int maximum_remainder;
    int answer = 0;

    for (a = 3; a <= 1000; a++) {
        maximum_remainder = 0;

        for (n = 1; n <= 2 * a; n++) {
            maximum_remainder = max(maximum_remainder, (modulus_power(a - 1, n, a * a) +
                                    modulus_power(a + 1, n, a * a)) % (a * a));
        }

        answer += maximum_remainder;
    }

    printf("%d", answer);

    return 0;
}
