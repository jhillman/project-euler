/* Problem 85 = 2772 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int gridWidth;
    int gridHeight;
    int total;
    int variance = 2000000;
    int answer = 0;

    for (gridWidth = 1; gridWidth < 100; gridWidth++) {
        for (gridHeight = 1; gridHeight < 100; gridHeight++) {
            total = ((gridWidth * (gridWidth + 1)) * (gridHeight * (gridHeight + 1))) / 4;

            if (abs(total - 2000000) < variance) {
                answer = gridWidth * gridHeight;
                variance = abs(total - 2000000);
            }
        }
    }

    printf("%d", answer);
    
    return 0;
}
