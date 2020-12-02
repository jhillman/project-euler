/* Problem 1 = 233168 */

#include <stdio.h>

int main() {
    int answer = 0;
    int i;

    for (i = 1; i <= 999; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            answer += i;
        }
    }

    printf("%d", answer);

    return 0;
}
