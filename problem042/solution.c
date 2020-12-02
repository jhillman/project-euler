/* Problem 42 = 162 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *words[] = {
#include "words.txt"
};

int main() {
    int count = sizeof(words) / sizeof(char *);
    int i;
    char *charPtr;
    int score;
    double term;
    int answer = 0;

    for (i = 0; i < count; i++) {
        score = 0;
        charPtr = words[i];

        while (*charPtr) {
            if (*charPtr >= 'A' && *charPtr <= 'Z') {
                score += (*charPtr - 'A' + 1);
            }

            ++charPtr;
        }

        /* inverse of (n * (n + 1)) / 2 = (sqrt(1 + 8 * n) - 1) / 2 */
        term = (sqrt(1 + 8 * score) - 1) / 2;

        if (term == (int)term) {
            ++answer;
        }
    }

    printf("%d", answer);

    return 0;
}
