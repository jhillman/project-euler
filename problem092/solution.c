/* Problem 92 = 8581146 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

int main() {
    int squares[] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    char numberString[8];
    int number;
    int digits;
    int answer = 0;

    for (a = 0; a <= 9; a++) {
        for (b = a; b <= 9; b++) {
            for (c = b; c <= 9; c++) {
                for (d = c; d <= 9; d++) {
                    for (e = d; e <= 9; e++) {
                        for (f = e; f <= 9; f++) {
                            for (g = f; g <= 9; g++) {
                                sprintf(numberString, "%d%d%d%d%d%d%d", a, b, c, d, e, f, g);
                                number = atoi(numberString);

                                while (number) {
                                    if (number == 1) {
                                        break;
                                    } else if (number == 89) {
                                        break;
                                    } else {
                                        digits = number;
                                        number = 0;

                                        while (digits) {
                                            number += squares[digits % 10];
                                            digits /= 10;
                                        }
                                    }
                                }

                                if (number == 89) {
                                    do {
                                        ++answer;
                                    } while (next_permutation(numberString, 7));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d", answer);
    
    return 0;
}
