/* Problem 33 = 100 */

#include <stdio.h>

int main() {
    int numerator;
    int denominator;
    int leftNumerator;
    int rightNumerator;
    int leftDenominator;
    int rightDenominator;
    int answerNumerator = 1;
    int answerDenominator = 1;

    for (numerator = 11; numerator <= 99; numerator++) {
        if (numerator % 10 == 0) {
            continue;
        }

        leftNumerator = numerator / 10;
        rightNumerator = numerator % 10;

        for (denominator = numerator + 1; denominator <= 99; denominator++) {
            if (denominator % 10 == 0) {
                continue;
            }

            leftDenominator = denominator / 10;
            rightDenominator = denominator % 10;

            if ((leftNumerator == rightNumerator && leftDenominator == rightDenominator) ||
                    rightNumerator != leftDenominator) {
                continue;
            }

            if ((double)leftNumerator / (double)rightDenominator == (double)numerator / (double)denominator) {
                answerNumerator *= leftNumerator;
                answerDenominator *= rightDenominator;
            }
        }
    }

    printf("%d", answerDenominator / answerNumerator);
    
    return 0;
}
