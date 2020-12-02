/* Problem 27 = -59231 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../algorithms.h"

int main() {
    int primes;
    int maximum = 0;
    int answer = 0;
    int a;
    int b;
    int n;
    int quadratic;

    for (a = -1000; a < 1000; a++) {
        for (b = 1; b < 1000; b += 2) {
            n = 0;
            primes = 0;
            quadratic = b;

            while (quadratic > 0 && is_prime(quadratic)) {
                quadratic = n * n + a * n + b;
                n++;
                primes++;
            }

            if (primes > maximum) {
                maximum = primes;
                answer = a * b;
            }
        }
    }

    printf("%d", answer);
    
    return 0;
}
