/* Problem 126 = 18522 */

#include <stdio.h>
#include <stdlib.h>

int layer_surface_area(int width, int length, int height, int layer) {
    return 4 * (width + length + height + layer - 2) * (layer - 1) +
           2 * (width * length + width * height + height * length);
}

int main() {
    int maximum = 20000;
    int *C = (int *)calloc(maximum, sizeof(int));
    int width;
    int length;
    int height;
    int layer;
    int number;
    int answer = 0;

    for (width = 1; layer_surface_area(width, width, width, 1) < maximum; width++) {
        for (length = width; layer_surface_area(width, length, width, 1) < maximum; length++) {
            for (height = length; layer_surface_area(width, length, height, 1) < maximum; height++) {
                for (layer = 1; layer_surface_area(width, length, height, layer) < maximum; layer++) {
                    ++C[layer_surface_area(width, length, height, layer)];
                }
            }
        }
    }

    number = 1;

    while (!answer) {
        if (C[number] == 1000) {
            answer = number;
        }

        ++number;
    }

    free(C);

    printf("%d", answer);

    return 0;
}
