/* Problem 137 = 1120149658760 */

#include <stdio.h>

long long fibonacci(int n) {
    long long number = 1;

    if (n > 2) {
        number = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return number;
}

int main() {
    int n = 15;
    long long answer = fibonacci(2 * n) * fibonacci(2 * n + 1);

    printf("%lld", answer);

    return 0;
}

