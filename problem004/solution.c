/* Problem 4 = 906609 */

#include <stdio.h>
#include <math.h>
#include "../algorithms.h"

int main() {
    struct list *factors;
    struct node *factorNode;
    int number = 999;
    int digits = 3;
    long long factor;
    long long candidateFactor;
    int factorDigits;
    long long first;
    long long second;
    int found = 0;

    long long palindrome = previous_palindrome(number * number);

    while (!found && palindrome > 1) {
        factors = prime_factors(palindrome);
        factorNode = factors->last;

        while (!found && factorNode) {
            candidateFactor = factor = factorNode->value;
            factorDigits = count_digits((palindrome / candidateFactor));

            while (factorDigits > digits) {
                candidateFactor += factor;
                factorDigits = count_digits((palindrome / candidateFactor));
            }

            if (factorDigits == digits) {
                for (first = candidateFactor; first >= factor && !found; first -= factor) {
                    if ((palindrome % first) == 0 &&
                            count_digits(first) == digits) {
                        second = palindrome / first;

                        if (count_digits(second) == digits) {
                            printf("%lld", palindrome);
                            found = 1;
                        }
                    }
                }
            }

            factorNode = factorNode->previous;
        }

        list_free(factors);

        if (!found) {
            palindrome = previous_palindrome(palindrome);
        }
    }

    return 0;
}
