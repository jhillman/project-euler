/* Problem 62 = 127035954683 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CUBES 10000

int compare(const void *a, const void *b) {
    return *((const char *)a) - *((const char *)b);
}

int main() {
    char cubes[MAX_CUBES][13];
    char cube[13];
    long long smallest;
    int count;
    int i;
    int j;
    long long answer = 0;

    for (i = 1000; !answer && i < MAX_CUBES; i++) {
        sprintf(cube, "%lld", (long long)pow(i, 3));
        qsort(cube, strlen(cube), sizeof(char), compare);
        strcpy(cubes[i], cube);
        count = 0;
        smallest = 0;

        for (j = 1000; j <= i; j++) {
            if (strcmp(cubes[j], cube) == 0) {
                if (smallest == 0) {
                    smallest = (long long)pow(j, 3);
                }

                ++count;
            }
        }

        if (count == 5) {
            answer = smallest;
        }
    }

    printf("%lld", answer);
    
    return 0;
}
