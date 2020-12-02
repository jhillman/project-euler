/* Problem 108 = 180180 */

#include <stdio.h>
#include <math.h>

int main() {
    int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43 };
    int exponents[32];
    int position;
    int prime;
    int i;
    int divisors = 2000;
    int number;
    long long answer = 0;

    do {
        position = 0;
        number = divisors;
        prime = 3;

        do {
            while (number % prime == 0) {
                number /= prime;
                exponents[position++] = prime;
            }

            prime += 2;
        } while (number > 1 && prime < 8);

        ++divisors;
    } while (number > 1);

    answer = 1;

    for (i = 0; i < position; i++) {
        answer *= (long long)(pow(primes[i], (exponents[position - 1 - i] - 1) / 2));
    }

    printf("%lld", answer);

    return 0;
}
