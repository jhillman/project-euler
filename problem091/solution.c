/* Problem 91 = 14234 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 50

int main() {
    int x1;
    int y1;
    int x2;
    int y2;
    double distanceOP;
    double distanceOQ;
    double distancePQ;
    double a;
    double b;
    double c;
    int answer = 0;

    for (x1 = 0; x1 <= MAX; x1++) {
        for (y1 = 0; y1 <= MAX; y1++) {
            for (x2 = 0; x2 <= MAX; x2++) {
                for (y2 = 0; y2 <= MAX; y2++) {
                    if (y2 - x2 < y1 - x1) {
                        distanceOP = sqrt(x1 * x1 + y1 * y1);
                        distanceOQ = sqrt(x2 * x2 + y2 * y2);
                        distancePQ = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

                        if (distanceOP && distanceOQ && distancePQ) {
                            if (distanceOP > distanceOQ && distanceOP > distancePQ) {
                                c = distanceOP;
                                a = distanceOQ;
                                b = distancePQ;
                            } else if (distanceOQ > distanceOP && distanceOQ > distancePQ) {
                                c = distanceOQ;
                                a = distanceOP;
                                b = distancePQ;
                            } else {
                                c = distancePQ;
                                a = distanceOP;
                                b = distanceOQ;
                            }

                            if (abs((int)((a * a + b * b) - (c * c))) < 1) {
                                ++answer;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d", answer);
    
    return 0;
}
