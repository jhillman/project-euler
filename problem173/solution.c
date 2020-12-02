/* Problem 173 = 1572729 */

#include <stdio.h>

int main() {
    long long maximum = 1000000;
    long long innerWidth = 1;
    long long innerArea;
    long long outerWidth;
    int answer = 0;
    innerArea = innerWidth * innerWidth;
    outerWidth = innerWidth + 2;

    do {
        while (outerWidth * outerWidth - innerArea <= maximum) {
            ++answer;
            outerWidth += 2;
        }

        ++innerWidth;
        innerArea = innerWidth * innerWidth;
        outerWidth = innerWidth + 2;
    } while (outerWidth * outerWidth - innerArea <= maximum);

    printf("%d", answer);

    return 0;
}
