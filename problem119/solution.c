/* Problem 119 = 248155780267521 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    long long difference = *(long long *)a - *(long long *)b;
    int result = 0;

    if (difference > 0) {
        result = 1;
    } else if (difference < 0) {
        result = -1;
    }

    return result;
}

int sum_digits(long long number) {
    int sum = 0;

    while (number) {
        sum += (number % 10);
        number /= 10;
    }

    return sum;
}

int main() {
    int n = 0;
    int number = 2;
    int power;
    int sum;
    long long result;
    long long numbers[31];
    long long answer = 0;

    while (n <= 30) {
        for (power = 2; n <= 30 && power < 10; power++) {
            result = (long long)pow(number, power);
            sum = sum_digits(result);

            if (sum == number) {
                numbers[n++] = result;
            }
        }

        ++number;
    }

    qsort(numbers, n, sizeof(long long), compare);
    answer = numbers[29];

    printf("%lld", answer);

    return 0;
}
