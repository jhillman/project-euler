/* Problem 206 = 1389019170 */

#include <stdio.h>
#include <math.h>

int main() {
    long long maximum = (long long)sqrt((double)1929394959697989990);
    long long current = maximum;
    long long trial;
    long long digit;
    int valid;
    long long answer = 0;

    do {
        trial = current * current;
        digit = 0;
        valid = 1;

        while (valid && trial) {
            valid = (trial % 10 == digit);
            --digit;

            if (digit < 0) {
                digit = 9;
            }

            trial /= 100;
        }

        if (valid) {
            answer = current;
        }

        --current;
    } while (!answer);

    printf("%lld", answer);
    
    return 0;
}
