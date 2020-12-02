/* Problem 68 = 6531031914842725 */

#include <stdio.h>
#include "../algorithms.h"

struct line {
    int outside;
    int middle;
    int inside;
};

int main() {
    struct line lines[5];
    int sums[5];
    char order[] = ":987654321";
    int length = (int)strlen(order);
    int maximum = 10;
    int minimum;
    int firstLine;
    int magic;
    int sum;
    int i;
    char solution[18];
    char *numberPtr;
    char answer[18] = "0";

    do {
        lines[0].outside = order[0] - '0';
        lines[0].middle = order[1] - '0';
        lines[0].inside = order[2] - '0';
        lines[1].outside = order[3] - '0';
        lines[1].middle = order[2] - '0';
        lines[1].inside = order[4] - '0';
        lines[2].outside = order[5] - '0';
        lines[2].middle = order[4] - '0';
        lines[2].inside = order[6] - '0';
        lines[3].outside = order[7] - '0';
        lines[3].middle = order[6] - '0';
        lines[3].inside = order[8] - '0';
        lines[4].outside = order[9] - '0';
        lines[4].middle = order[8] - '0';
        lines[4].inside = order[1] - '0';
        minimum = maximum;
        firstLine = 0;

        for (i = 0; i < 5; i++) {
            sums[i] = lines[i].outside + lines[i].middle + lines[i].inside;

            if (lines[i].outside < minimum) {
                minimum = lines[i].outside;
                firstLine = i;
            }
        }

        magic = 1;
        sum = sums[0];

        for (i = 1; magic && i < 5; i++) {
            magic = (sum == sums[i]);
        }

        if (magic) {
            numberPtr = solution;

            for (i = firstLine; i < 5; i++) {
                numberPtr += sprintf(numberPtr, "%d%d%d",
                                     lines[i].outside, lines[i].middle, lines[i].inside);
            }

            for (i = 0; i < firstLine; i++) {
                numberPtr += sprintf(numberPtr, "%d%d%d",
                                     lines[i].outside, lines[i].middle, lines[i].inside);
            }

            if (strlen(solution) == 16 && strcmp(solution, answer) > 0) {
                strcpy(answer, solution);
            }
        }
    } while (previous_permutation(order, length));

    printf("%s", answer);
    
    return 0;
}
