/* Problem 67 = 7273 */

#include <stdio.h>
#include <stdlib.h>

#define TRIANGLE_WIDTH 100

#ifdef max
#undef max
#endif
#define max( x, y ) ( ( x ) > ( y ) ? ( x ) : ( y ) )

int main() {
    FILE *triangleFile;
    int triangle[TRIANGLE_WIDTH][TRIANGLE_WIDTH];
    int i;
    int j;
    int fscanfResult;
    int value;
    int answer;
    triangleFile = fopen("triangle.txt", "r");

    if (triangleFile) {
        fscanfResult = fscanf(triangleFile, "%d ", &triangle[0][0]);

        for (i = 1; i < TRIANGLE_WIDTH; i++) {
            for (j = 0; j < i + 1; j++) {
                fscanfResult = fscanf(triangleFile, "%d ", &triangle[i][j]);
            }

            for (j = 0; j < i + 1; j++) {
                value = triangle[i][j];

                if (j == 0) {
                    triangle[i][j] = value + triangle[i - 1][j];
                } else if (j == i) {
                    triangle[i][j] = value + triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] = max(value + triangle[i - 1][j],
                                         value + triangle[i - 1][j - 1]);
                }
            }
        }

        answer = 0;

        for (j = 0; j < TRIANGLE_WIDTH; j++) {
            answer = max(answer, triangle[TRIANGLE_WIDTH - 1][j]);
        }

        fclose(triangleFile);
        
        printf("%d", answer);
    }

    return 0;
}
