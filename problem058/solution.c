/* Problem 58 = 26241 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    int numbers = 1;
    int primes = 0;
    int answer = 0;
    int n = 1;

    while (1) {
        numbers += 4;
        n += 2;
        /* bottom right: n^2          */
        /* bottom left:  n^2 - n + 1  */
        /* top left:     n^2 - 2n + 2 */
        /* top right:    n^2 - 3n + 3 */
        primes += is_prime((n * n) - n + 1);
        primes += is_prime((n * n) - (2 * n) + 2);
        primes += is_prime((n * n) - (3 * n) + 3);

        if ((double)primes / (double)numbers < 0.10) {
            answer = n;
            break;
        }
    }

    printf("%d", answer);
    
    return 0;
}
