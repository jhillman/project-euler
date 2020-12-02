/* Problem 73 = 5066251 */

#include <stdio.h>

int main() {
    int n = 10000;
    int numerator = 1;
    int denominator = 1;
    int nextNumerator = 1;
    int nextDenominator = 2;
    int tempNumerator;
    int tempDenominator;
    int k;
    int answer = 0;

    while (numerator != 1 || denominator != 3) {
        k = (n + denominator) / nextDenominator;
        tempNumerator = numerator;
        tempDenominator = denominator;
        numerator = nextNumerator;
        denominator = nextDenominator;
        nextNumerator = k * nextNumerator - tempNumerator;
        nextDenominator = k * nextDenominator - tempDenominator;
        ++answer;
    }

    printf("%d", answer - 2);
    
    return 0;
}
