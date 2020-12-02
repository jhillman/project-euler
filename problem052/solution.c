/* Problem 52 = 142857 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return *((const char *)a) - *((const char *)b);
}

int main() {
    char numberx1[7];
    char numberx2[7];
    char numberx3[7];
    char numberx4[7];
    char numberx5[7];
    char numberx6[7];
    int answer = 0;
    int number = 1;

    while (!answer) {
        sprintf(numberx1, "%d", number);
        sprintf(numberx2, "%d", number * 2);
        qsort(numberx1, strlen(numberx1), sizeof(char), compare);
        qsort(numberx2, strlen(numberx2), sizeof(char), compare);

        if (strcmp(numberx1, numberx2) == 0) {
            sprintf(numberx3, "%d", number * 3);
            qsort(numberx3, strlen(numberx3), sizeof(char), compare);

            if (strcmp(numberx2, numberx3) == 0) {
                sprintf(numberx4, "%d", number * 4);
                qsort(numberx4, strlen(numberx4), sizeof(char), compare);

                if (strcmp(numberx3, numberx4) == 0) {
                    sprintf(numberx5, "%d", number * 5);
                    qsort(numberx5, strlen(numberx5), sizeof(char), compare);

                    if (strcmp(numberx4, numberx5) == 0) {
                        sprintf(numberx6, "%d", number * 6);
                        qsort(numberx6, strlen(numberx6), sizeof(char), compare);

                        if (strcmp(numberx5, numberx6) == 0) {
                            answer = number;
                        }
                    }
                }
            }
        }

        ++number;
    }

    printf("%d", answer);
    
    return 0;
}
