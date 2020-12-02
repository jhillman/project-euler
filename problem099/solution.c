/* Problem 99 = 709 */

#include <stdio.h>
#include <math.h>

int main() {
    FILE *baseExponentFile;
    int line;
    int fscanfResult;
    int base;
    int exponent;
    int maximum = 0;
    int answer = 0;
    baseExponentFile = fopen("base_exp.txt", "r");

    if (baseExponentFile) {
        for (line = 1; line <= 1000; line++) {
            fscanfResult = fscanf(baseExponentFile, "%d,%d ", &base, &exponent);

            if (exponent * log(base) > maximum) {
                maximum = (int)(exponent * log(base));
                answer = line;
            }
        }

        fclose(baseExponentFile);
    }

    printf("%d", answer);

    return 0;
}
