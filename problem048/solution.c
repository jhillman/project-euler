/* Problem 48 = 9110846700 */

#include <stdio.h>

int main() {
    unsigned long long product;
    unsigned long long i;
    unsigned long long j;
    unsigned long long answer = 0;

    for (i = 1; i <= 1000; i++) {
        product = i;

        for (j = 1; j < i; j++) {
            product *= i;
            product %= 10000000000LL;
        }

        answer += product;
    }

    printf("%lld", answer % 10000000000LL);
    
    return 0;
}
