/* Problem 69 = 510510 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    char *sieve = (char *)calloc(100, sizeof(char));
    int answer = 1;
    int n = 2;
    sieve_primes(sieve, 100);

    for (n = 2; n <= 100; n++) {
        if (!sieve[n]) {
            if (answer * n > 1000000) {
                break;
            } else {
                answer *= n;
            }
        }
    }

    free(sieve);

    printf("%d", answer);
    
    return 0;
}
