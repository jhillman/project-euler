/* Problem 123 = 21035 */

#include <stdio.h>
#include "../algorithms.h"
#include "../list_math.h"

/* http://en.wikipedia.org/wiki/Modular_exponentiation */
long long list_modulus_power(long long base, long long exponent, long long modulus) {
    long long result = 1;
    struct list *multiplicand_list;
    struct list *multiplier_list;
    struct list *divisor = 0;
    struct list *modulus_result;
    struct list *modulus_list = list_from_number(modulus);

    do {
        if (exponent & 0x1) {
            if (result) {
                multiplicand_list = list_from_number(result);
                multiplier_list = list_from_number(base);
                divisor = 0;
                list_multiply_list(multiplicand_list, multiplier_list, &divisor);
                list_modulus_list(divisor, modulus_list, &modulus_result);

                if (modulus_result->length) {
                    result = modulus_result->first->value;

                    if (modulus_result->length > 1) {
                        result *= (long long)pow(10, LIST_NUMBER_LENGTH);
                        result += modulus_result->last->value;
                    }
                } else {
                    result = 0;
                }

                list_free(modulus_result);
                list_free(multiplicand_list);
                list_free(multiplier_list);
                list_free(divisor);
            }
        }

        if (base) {
            multiplicand_list = list_from_number(base);
            multiplier_list = list_from_number(base);
            divisor = 0;
            list_multiply_list(multiplicand_list, multiplier_list, &divisor);
            list_modulus_list(divisor, modulus_list, &modulus_result);

            if (modulus_result->length) {
                base = modulus_result->first->value;

                if (modulus_result->length > 1) {
                    base *= (long long)pow(10, LIST_NUMBER_LENGTH);
                    base += modulus_result->last->value;
                }
            } else {
                base = 0;
            }

            list_free(modulus_result);
            list_free(multiplicand_list);
            list_free(multiplier_list);
            list_free(divisor);
        }

        exponent >>= 1;
    } while (exponent);

    list_free(modulus_list);

    return result;
}

int main() {
    char *sieve = (char *)calloc(1000000, sizeof(char));
    long long n;
    long long primes[80000];
    int count = 1;
    long long remainder;
    long long answer = 0;
    sieve_primes(sieve, 1000000);

    for (n = 2; n < 1000000; n++) {
        if (!sieve[n]) {
            primes[count++] = n;
        }
    }

    free(sieve);
    n = 1;

    while (!answer) {
        /*
        remainder = (list_modulus_power(primes[n] - 1, n, primes[n] * primes[n]) +
                     list_modulus_power(primes[n] + 1, n, primes[n] * primes[n])) % (primes[n] * primes[n]);
        */
        remainder = 2 * (n + 1) * primes[n];

        if (remainder > 10000000000LL) {
            answer = n + 1;
        }

        ++n;
    }

    printf("%lld", answer);

    return 0;
}
