/* Problem 22 = 871198282 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../list.h"

int compare(const void *a, const void *b) {
    const char **stringOne = (const char **)a;
    const char **stringTwo = (const char **)b;
    return strcmp(*stringOne, *stringTwo);
}

char *nameArray[] = {
#include "names.txt"
};

int main() {
    int count = sizeof(nameArray) / sizeof(char *);
    char *charPtr;
    int score;
    int answer = 0;
    int i;
    qsort(nameArray, count, sizeof(char *), compare);

    for (i = 0; i < count; i++) {
        charPtr = nameArray[i];
        score = 0;

        while (*charPtr) {
            if (*charPtr >= 'A' && *charPtr <= 'Z') {
                score += (*charPtr - 'A' + 1);
            }

            ++charPtr;
        }

        answer += score * (i + 1);
    }

    printf("%d", answer);
    
    return 0;
}
