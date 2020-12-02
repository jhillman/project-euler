/* Problem 109 = 38182 */

#include <stdio.h>

int main() {
    int scores[3 * 20 + 2 + 1];
    int i;
    int score;
    int first;
    int second;
    int third;
    int answer = 0;
    score = 0;

    for (i = 0; i <= 20; i++) {
        scores[i] = score;
        ++score;
    }

    scores[i] = 25;
    score = 1;

    for (i = i + 1; i < 2 * 20 + 2; i++) {
        scores[i] = 2 * score;
        ++score;
    }

    scores[i] = 2 * 25;
    score = 1;

    for (i = i + 1; i < 3 * 20 + 3; i++) {
        scores[i] = 3 * score;
        ++score;
    }

    for (first = 0; first <= 3 * 20 + 2; first++) {
        for (second = first; second <= 3 * 20 + 2; second++) {
            for (third = 20 + 2; third <= 2 * 20 + 2; third++) {
                answer += (scores[first] + scores[second] + scores[third] < 100);
            }
        }
    }

    printf("%d", answer);

    return 0;
}
