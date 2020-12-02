/* Problem 101 = 37076114526 */

#include <stdio.h>
#include <math.h>

/* http://en.wikipedia.org/wiki/Lagrange_polynomial */
long long lagrange(double numbers[], double values[], int degree, double number) {
    double value = 0;
    double weight;
    int i;
    int j;

    for (i = 1; i <= degree; i++) {
        weight = 1;

        for (j = 1; j <= degree; j++) {
            if (i != j) {
                weight *= (number - numbers[j]) / (numbers[i] - numbers[j]);
            }
        }

        value += weight * values[i];
    }

    if (value - (long long)value > .9) {
        value = ceil(value);
    } else {
        value = floor(value);
    }

    return (long long)value;
}

long long function(long long n) {
    return 1 -
           n +
           n * n -
           n * n * n +
           n * n * n * n -
           n * n * n * n * n +
           n * n * n * n * n * n -
           n * n * n * n * n * n * n +
           n * n * n * n * n * n * n * n -
           n * n * n * n * n * n * n * n * n +
           n * n * n * n * n * n * n * n * n * n;
}

int main() {
    int i;
    double numbers[16];
    double values[16];
    long long value;
    long long answer = 0;

    for (i = 0; i <= 15; i++) {
        numbers[i] = (double)i;
        values[i] = (double)function(i);
    }

    for (i = 0; i < 16; i++) {
        value = lagrange(numbers, values, i, (double)i + 1);

        if ((double)value != values[i + 1]) {
            answer += value;
        } else {
            break;
        }
    }

    printf("%lld", answer);

    return 0;
}
