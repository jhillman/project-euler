/* Problem 100 = 756872327473 */

#include <stdio.h>

int main() {
    long long blue = 14;
    long long oldBlue;
    long long total = 20;
    long long answer = 0;

    while (!answer) {
        if (blue + total > 1000000000000LL) {
            answer = blue + 1;
        } else {
            oldBlue = blue;
            blue = 3 * blue + 2 * total + 2;
            total = 4 * oldBlue + 3 * total + 3;
        }
    }

    printf("%lld", answer);

    return 0;
}
