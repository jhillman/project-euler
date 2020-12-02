/* Problem 97 = 8739992577 */

#include <stdio.h>

int main() {
    unsigned long long answer = 2;
    unsigned long long i;

    for (i = 1; i < 7830457; i++) {
        answer *= 2;
        answer %= 10000000000LL;
    }

    answer *= 28433;
    answer %= 10000000000LL;
    answer += 1;

    printf("%lld", answer % 10000000000LL);

    return 0;
}
