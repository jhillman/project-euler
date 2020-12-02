/* Problem 90 = 1217 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    char digits[] = "0123456789";
    int length = (int)strlen(digits);
    char cube[7];
    char *digitPtr;
    /* 1111110000b = 1008 */
    int *unique = (int *)calloc(1009, sizeof(int));
    /* 10 C 6 = 210 */
    char cubes[210][7];
    int cubeCount = 0;
    int i;
    int j;
    char *cubeOne;
    char *cubeTwo;
    char digit;
    int mask;
    char squares[][2] = { 
        { '0', '1' }, { '0', '4' }, { '0', '9' },
        { '1', '9' }, { '2', '5' }, { '3', '9' },
        { '4', '9' }, { '9', '4' }, { '8', '1' }
    };
    int k;
    int allSquares;
    int answer = 0;

    do {
        strncpy(cube, digits, 6);
        cube[6] = 0;
        mask = 0;

        for (digit = '0'; digit <= '9'; digit++) {
            if (strchr(cube, digit)) {
                mask |= (1 << (digit - '0'));
            }
        }

        if (!unique[mask]) {
            unique[mask] = 1;

            if ((digitPtr = strchr(cube, '6'))) {
                *digitPtr = '9';
            }

            strcpy(cubes[cubeCount++], cube);
        }
    } while (next_permutation(digits, length));

    free(unique);

    for (i = 0; i < cubeCount; i++) {
        cubeOne = cubes[i];

        for (j = i; j < cubeCount; j++) {
            cubeTwo = cubes[j];
            allSquares = 1;

            if (allSquares) {
                for (k = 0; allSquares && k < 9; k++) {
                    allSquares = allSquares &&
                                 (strchr(cubeOne, squares[k][0]) && strchr(cubeTwo, squares[k][1])) ||
                                 (strchr(cubeTwo, squares[k][0]) && strchr(cubeOne, squares[k][1]));
                }
            }

            answer += allSquares;
        }
    }

    printf("%d", answer);
    
    return 0;
}
