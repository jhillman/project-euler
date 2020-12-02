/* Problem 17 = 21124 */

#include <stdio.h>
#include <string.h>

int main() {
    int letters = 0;
    char *numberWords[] = {
        "",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten"
    };
    char *tensWords[] = {
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"
    };
    char *teensWords[] = {
        "",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    };
    int number;
    int addAnd;
    int addDash;
    char numberString[1000];
    char *charPtr;
    int i;

    for (i = 1; i <= 1000; i++) {
        number = i;
        strcpy(numberString, "");

        if (number / 1000 >= 1) {
            strcat(numberString, numberWords[number / 1000]);
            strcat(numberString, " thousand");
            number = number % 1000;
        }

        addAnd = 0;

        if (number / 100 >= 1) {
            strcat(numberString, numberWords[number / 100]);
            strcat(numberString, " hundred");
            number = (number % 100);
            addAnd = 1;
        }

        addDash = 0;

        if (number / 10 >= 2) {
            if (addAnd) {
                strcat(numberString, " and ");
                addAnd = 0;
            }

            strcat(numberString, tensWords[number / 10]);
            number = (number % 10);
            addDash = 1;
        } else if (((float)number / 10) > 1) {
            if (addAnd) {
                strcat(numberString, " and ");
                addAnd = 0;
            }

            strcat(numberString, teensWords[number - 10]);
            number = 0;
        }

        if (number > 0) {
            if (addAnd) {
                strcat(numberString, " and ");
            }

            if (addDash) {
                strcat(numberString, "-");
            }

            strcat(numberString, numberWords[number]);
        }

        charPtr = numberString;

        while (*charPtr) {
            letters += (*charPtr >= 'a' && *charPtr <= 'z');
            ++charPtr;
        }
    }

    printf("%d", letters);
    
    return 0;
}
