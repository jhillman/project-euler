/* Problem 45 = 1533776805 */

#include <stdio.h>
#include <math.h>

int is_pentagonal(long long pentagonal) {
    double n = (sqrt(24 * (double)pentagonal + 1) + 1) / 6;
    
    return (n == (long long)n);
}

int is_hexagonal(long long hexagonal) {
    double n = (sqrt(8 * (double)hexagonal + 1) + 1) / 4;
    
    return (n == (long long)n);
}

int main() {
    long long triangle;
    long long answer = 0;
    long long n = 286;

    while (!answer) {
        triangle = (n * (n + 1)) / 2;

        if (is_pentagonal(triangle) && is_hexagonal(triangle)) {
            answer = triangle;
        }

        ++n;
    }

    printf("%lld", answer);

    return 0;
}
