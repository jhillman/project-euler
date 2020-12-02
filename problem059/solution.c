/* Problem 59 = 107359 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *cipherFile;
    int values = 0;
    int *encrypted;
    int *original;
    int fscanfResult;
    char a;
    char b;
    char c;
    int spaces;
    int maxSpaces = 0;
    char bestA = ' ';
    char bestB = ' ';
    char bestC = ' ';
    int i;
    int answer = 0;
    cipherFile = fopen("cipher1.txt", "r");

    if (cipherFile) {
        while (fscanf(cipherFile, "%d,", &i) == 1) {
            ++values;
        }

        encrypted = (int *)malloc(values * sizeof(int));
        original = (int *)malloc(values * sizeof(int));
        fseek(cipherFile, 0, SEEK_SET);

        for (i = 0; i < values; i++) {
            fscanfResult = fscanf(cipherFile, "%d,", &encrypted[i]);
        }

        fclose(cipherFile);

        for (a = 'a'; a <= 'z'; a++) {
            for (b = 'b'; b <= 'z'; b++) {
                for (c = 'c'; c <= 'z'; c++) {
                    spaces = 0;

                    for (i = 0; i < values; i += 3) {
                        spaces += ((original[i] = encrypted[i] ^ a) == ' ');

                        if (i + 1 < values) {
                            spaces += ((original[i + 1] = encrypted[i + 1] ^ b) == ' ');
                        }

                        if (i + 2 < values) {
                            spaces += ((original[i + 2] = encrypted[i + 2] ^ c) == ' ');
                        }
                    }

                    if (i >= values) {
                        if (spaces > maxSpaces) {
                            maxSpaces = spaces;
                            bestA = a;
                            bestB = b;
                            bestC = c;
                        }
                    }
                }
            }
        }

        for (i = 0; i < values; i += 3) {
            answer += encrypted[i] ^ bestA;

            if (i + 1 < values) {
                answer += encrypted[i + 1] ^ bestB;
            }

            if (i + 2 < values) {
                answer += encrypted[i + 2] ^ bestC;
            }
        }

        free(encrypted);
        free(original);
        
        printf("%d", answer);
    }

    return 0;
}
