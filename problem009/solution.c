/* Problem 9 = 31875000 */

#include <stdio.h>

int main() {
    int number = 1000;
    int found = 0;
    int a;
    int b;
    int c;

    for (a = 1; !found && a < number; a++) {
        for (b = (a + 1); !found && b <= number; b++) {
            c = number - a - b;

            if ((a * a + b * b) == (c * c)) {
                if (a + b + c == number) {
                    printf("%d", a * b * c);
                    found = 1;
                }
            }
        }
    }

    return 0;
}
