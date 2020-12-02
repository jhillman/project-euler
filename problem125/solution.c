/* Problem 125 = 2906969179 */

#include <stdio.h>
#include <math.h>
#include "../list_math.h"

int is_palindrome(long long number) {
    long long forward = number;
    long backward = 0;

    while (number) {
        backward *= 10;
        backward += number % 10;
        number /= 10;
    }

    return (forward == backward);
}

int main() {
    int maximum = 100000000;
    int maximumBase = (int)sqrt((double)maximum / 2);
    int *squares = malloc((maximumBase + 1) * sizeof(int));
    struct list *found = list_new();
    int n;
    long long sum = 0;
    int addend;
    long long answer = 0;

    for (n = 1; n <= maximumBase; n++) {
        squares[n] = n * n;
    }

    for (n = maximumBase; n > 0; n--) {
        sum = squares[n];

        for (addend = n - 1; addend > 0; addend--) {
            sum += squares[addend];

            if (sum < maximum && is_palindrome(sum) && !list_find(found, sum)) {
                list_push(found, sum);
            }
        }
    }

    answer = list_sum(found);
    free(squares);
    list_free(found);

    printf("%lld", answer);

    return 0;
}
