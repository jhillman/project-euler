/* Problem 60 = 26033 */

#include <stdio.h>
#include "../algorithms.h"

#define MAX_INDIVIDUAL_PRIME 10000
#define MAX_SIEVED_PRIME 1000000

int is_concatenation_prime(int primeOne, int primeTwo, char *sieve, int *primes) {
    long long concatenation = (primeOne * ((long long)pow(10, count_digits(primeTwo)))) + primeTwo;
    int prime = 0;
    int i;

    if (concatenation < MAX_SIEVED_PRIME) {
        prime = !sieve[concatenation];
    } else {
        for (i = 0; !prime && i < MAX_INDIVIDUAL_PRIME; i++) {
            if (primes[i] * primes[i] > concatenation) {
                prime = 1;
            }

            if (concatenation % primes[i] == 0) {
                break;
            }
        }
    }

    return prime;
}

char concatenable[MAX_INDIVIDUAL_PRIME][MAX_INDIVIDUAL_PRIME];

int main() {
    int i;
    char *sieve = (char *)calloc(MAX_SIEVED_PRIME, sizeof(char));
    int primes[MAX_INDIVIDUAL_PRIME];
    int primeCount = 0;
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    int answer = 0;
    sieve_primes(sieve, MAX_SIEVED_PRIME);

    for (i = 0; i < MAX_INDIVIDUAL_PRIME; i++) {
        if (!sieve[i]) {
            primes[primeCount++] = i;
        }
    }

    for (first = 0; !answer && first < primeCount; first++) {
        for (second = 0; !answer && second < first; second++) {
            concatenable[first][second] =
                (char)(is_concatenation_prime(primes[first], primes[second], sieve, primes) &&
                       is_concatenation_prime(primes[second], primes[first], sieve, primes));
        }

        for (second = 0; !answer && second < first; second++) {
            if (concatenable[first][second]) {
                for (third = 0; !answer && third < second; third++) {
                    if (concatenable[first][third] &&
                            concatenable[second][third]) {
                        for (fourth = 0; !answer && fourth < third; fourth++) {
                            if (concatenable[first][fourth] &&
                                    concatenable[second][fourth] &&
                                    concatenable[third][fourth]) {
                                for (fifth = 0; !answer && fifth < fourth; fifth++) {
                                    if (concatenable[first][fifth] &&
                                            concatenable[second][fifth] &&
                                            concatenable[third][fifth] &&
                                            concatenable[fourth][fifth]) {
                                        answer = primes[first] +
                                                 primes[second] +
                                                 primes[third] +
                                                 primes[fourth] +
                                                 primes[fifth];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    free(sieve);
    
    printf("%d", answer);

    return 0;
}
