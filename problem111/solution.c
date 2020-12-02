/* Problem 111 = 612407567715 */

#include <stdio.h>
#include "../algorithms.h"
#include "../list_math.h"

void replace(char *string, char find, char replace) {
    char *character = string;

    while (*character) {
        *character = *character == find ? replace : *character;
        ++character;
    }
}

int main() {
    char template[11];
    char number[11];
    int first;
    int second;
    int digit;
    long long potential;
    int position;
    struct list *prime_list[10][2];
    long long answer = 0;

    for (digit = 0; digit < 10; digit++) {
        prime_list[digit][0] = list_new();
        prime_list[digit][1] = list_new();
    }

    for (first = 0; first < 10; first++) {
        for (second = first; second < 10; second++) {
            strcpy(template, "--------^$");
            replace(template, '^', (char)('0' + first));
            replace(template, '$', (char)('0' + second));

            do {
                for (digit = 0; digit < 10; digit++) {
                    strcpy(number, template);
                    replace(number, '-', (char)('0' + digit));

                    if (*number != '0') {
                        potential = (long long)atof(number);

                        if (is_prime(potential)) {
                            position = (first != digit) + (second != digit) - 1;

                            if (!list_find(prime_list[digit][position], potential)) {
                                list_push(prime_list[digit][position], potential);
                            }
                        }
                    }
                }
            } while (next_permutation(template, 10));
        }
    }

    for (digit = 0; digit < 10; digit++) {
        if (prime_list[digit][0]->length) {
            answer += list_sum(prime_list[digit][0]);
        } else {
            answer += list_sum(prime_list[digit][1]);
        }

        list_free(prime_list[digit][0]);
        list_free(prime_list[digit][1]);
    }

    printf("%lld", answer);

    return 0;
}
