/* Problem 86 = 1818 */

#include <stdio.h>
#include <math.h>

int main() {
    int a;
    int bc;
    double distance;
    int integerSolutions = 0;
    int answer = 0;

    for (a = 1; !answer; a++) {
        for (bc = 1; !answer && bc <= a + a; bc++) {
            distance = sqrt(a * a + bc * bc);

            if (distance == (int)distance) {
                if (bc > a + 1) {
                    integerSolutions += (a + a + 2 - bc) / 2;
                } else {
                    integerSolutions += bc / 2;
                }

                if (integerSolutions > 1000000) {
                    answer = a;
                }
            }
        }
    }

    printf("%d", answer);
    
    return 0;
}
