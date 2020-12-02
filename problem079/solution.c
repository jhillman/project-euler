/* Problem 79 = 73162890 */

#include <stdio.h>
#include <string.h>

int main() {
    FILE *attemptsFile;
    char attempts[50][3];
    char answer[11] = { 0 };
    int fscanfResult;
    int digits;
    char *digitPtrOne;
    char *digitPtrTwo;
    char *digitPtrThree;
    char digitTemp;
    int i;
    int j;
    digitPtrOne = answer;
    attemptsFile = fopen("keylog.txt", "r");

    if (attemptsFile) {
        for (i = 0; i < 50; i++) {
            fscanfResult = fscanf(attemptsFile, "%d ", &digits);

            for (j = 0; j < 3; j++) {
                attempts[i][2 - j] = ('0' + digits % 10);
                digits /= 10;

                if (!strchr(answer, attempts[i][2 - j])) {
                    *digitPtrOne = attempts[i][2 - j];
                    ++digitPtrOne;
                    *digitPtrOne = 0;
                }
            }
        }

        fclose(attemptsFile);

        for (i = 0; i < 50; i++) {
            digitPtrOne = strchr(answer, attempts[i][0]);
            digitPtrTwo = strchr(answer, attempts[i][1]);
            digitPtrThree = strchr(answer, attempts[i][2]);

            if (digitPtrOne > digitPtrTwo) {
                digitTemp = *digitPtrOne;
                *digitPtrOne = *digitPtrTwo;
                *digitPtrTwo = digitTemp;
            }

            if (digitPtrTwo > digitPtrThree) {
                digitTemp = *digitPtrTwo;
                *digitPtrTwo = *digitPtrThree;
                *digitPtrThree = digitTemp;
            }
        }

        printf("%s", answer);
    }

    return 0;
}
