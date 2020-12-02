/* Problem 2 = 4613732 */

#include <stdio.h>

int main() {
    int first = 1;
    int second = 2;
    int answer = 2;

    while (1) {
        int next = first + second;
        first = second;
        second = next;

        if (next > 4000000) {
            break;
        }

        if (next % 2 == 0) {
            answer += next;
        }
    }

    printf("%d", answer);

    return 0;
}
