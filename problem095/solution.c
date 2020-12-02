/* Problem 95 = 14316 */

#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

#ifdef min
#undef min
#endif
#define min(x, y) ((x) < (y) ? (x) : (y))

#ifdef max
#undef max
#endif
#define max(x, y) ((x) > (y) ? (x) : (y))

int main() {
    int maximum = 1000000;
    int number;
    int factor;
    int divisor;
    int *sums = (int *)calloc(maximum, sizeof(int));
    int *links = (int *)calloc(maximum, sizeof(int));
    int current;
    int next;
    int length;
    int amicable;
    int minimum;
    int maxLength = 0;
    int answer = 0;

    for (number = 1; number <= maximum; number++) {
        factor = 2;
        divisor = number * factor;

        while (divisor < maximum) {
            sums[divisor] = number + sums[divisor];
            divisor = number * ++factor;
        }
    }

    for (number = 1; number < maximum; number++) {
        links[number] = number;
        current = minimum = number;
        length = 0;

        do {
            next = sums[current];
            minimum = min(minimum, next);
            amicable = 0;

            if (next == 0 || next > maximum || links[next] == number) {
                amicable = (next == number);
                break;
            } else {
                links[next] = number;
                current = next;
                ++length;
            }
        } while (current < maximum);

        if (amicable) {
            if (length > maxLength) {
                maxLength = length;
                answer = minimum;
            }
        }
    }

    free(sums);
    free(links);

    printf("%d", answer);

    return 0;
}
