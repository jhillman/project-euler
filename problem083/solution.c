/* Problem 83 = 425185 */

#include <stdio.h>
#include <stdlib.h>

#ifdef min
#undef min
#endif
#define min(x, y) ((x) < (y) ? (x) : (y))

int main() {
    FILE *matrixFile;
    int matrix[80][80];
    int minimums[80][80];
    int fscanfResult;
    int i;
    int j;
    int minimum;
    int changed;
    int answer;
    matrixFile = fopen("matrix.txt", "r");

    if (matrixFile) {
        for (i = 0; i < 80; i++) {
            for (j = 0; j < 80; j++) {
                fscanfResult = fscanf(matrixFile, "%d,", &matrix[i][j]);
                minimums[i][j] = 1000000;
            }
        }
    }

    fclose(matrixFile);
    minimums[0][0] = matrix[0][0];
    changed = 1;

    while (changed) {
        changed = 0;

        for (i = 0; i < 80; i++) {
            for (j = 0; j < 80; j++) {
                minimum = minimums[i][j];

                if (i > 0) {
                    minimum = min(minimums[i - 1][j] + matrix[i][j], minimum);
                }

                if (i < 79) {
                    minimum = min(minimums[i + 1][j] + matrix[i][j], minimum);
                }

                if (j > 0) {
                    minimum = min(minimums[i][j - 1] + matrix[i][j], minimum);
                }

                if (j < 79) {
                    minimum = min(minimums[i][j + 1] + matrix[i][j], minimum);
                }

                if (minimums[i][j] != minimum) {
                    minimums[i][j] = minimum;
                    changed = 1;
                }
            }
        }
    }

    answer = minimums[79][79];

    printf("%d", answer);

    return 0;
}
