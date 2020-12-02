/* Problem 89 = 743 */

#include <stdio.h>
#include <string.h>

void minimize(char *numeral, char *expanded, char *minimal) {
    char *position;
    int numeralLength = strlen(numeral);
    int expandedLength = strlen(expanded);
    int minimalLength = strlen(minimal);
    int i;

    while ((position = strstr(numeral, expanded))) {
        for (i = position - numeral; i < numeralLength; i++) {
            numeral[i + minimalLength] = numeral[i + expandedLength];
        }
        strncpy(position, minimal, strlen(minimal));
    }
}

int main() {
    FILE *numeralsFile;
    char numeral[20];
    char minimizedNumeral[20];
    int answer = 0;
    numeralsFile = fopen("roman.txt", "r");

    if (numeralsFile) {
        while (fgets(numeral, 20, numeralsFile)) {
            strcpy(minimizedNumeral, numeral);
            minimize(minimizedNumeral, "DCCCC", "CM");
            minimize(minimizedNumeral, "CCCC",  "CD");
            minimize(minimizedNumeral, "LXXXX", "XC");
            minimize(minimizedNumeral, "XXXX",  "XL");
            minimize(minimizedNumeral, "VIIII", "IX");
            minimize(minimizedNumeral, "IIII",  "IV");
            answer += strlen(numeral) - strlen(minimizedNumeral);
        }

        fclose(numeralsFile);
    }

    printf("%d", answer);
    
    return 0;
}
