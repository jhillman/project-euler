/* Problem 39 = 840 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a;
    int b;
    int c;
    int *perimeters = (int *)calloc(1001, sizeof(int));
    int i;
    int answer = 0;

    for (a = 1; a <= 1000; a++) {
        for (b = 1; a + b <= 1000; b++) {
            c = (int)sqrt(a * a + b * b);

            if (c * c == (a * a + b * b) && a + b + c <= 1000) {
                ++perimeters[a + b + c];
            }
        }
    }

    for (i = 0; i <= 1000; i++) {
        if (perimeters[i] > perimeters[answer]) {
            answer = i;
        }
    }

    free(perimeters);

    printf("%d", answer);
    
    return 0;
}
