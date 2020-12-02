/* Problem 66 = 661 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct triplet {
    int addend;
    int denominator;
    int squareRoot;
};

int main() {
    struct triplet *triplets[1000];
    struct triplet *triplet;
    int count;
    int addend;
    int denominator;
    int squareRoot;
    int i;
    int j;
    int repeated;
    int maximum = 0;
    int answer = 0;

    for (i = 0; i <= 1000; i++) {
        squareRoot = (int)sqrt(i);

        if (squareRoot * squareRoot != i) {
            addend = 0;
            denominator = 1;
            count = 0;
            repeated = 0;

            do {
                triplet = triplets[count] = (struct triplet *)malloc(sizeof(struct triplet));
                /* http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion */
                triplet->addend = denominator * squareRoot - addend;
                triplet->denominator = (i - (triplet->addend * triplet->addend)) / denominator;
                triplet->squareRoot = ((int)sqrt(i) + triplet->addend) / triplet->denominator;

                for (j = 0; !repeated && j < count - 1; j++) {
                    if (triplet->addend == triplets[j]->addend &&
                            triplet->denominator == triplets[j]->denominator &&
                            triplet->squareRoot == triplets[j]->squareRoot) {
                        repeated = 1;
                    }
                }

                addend = triplet->addend;
                denominator = triplet->denominator;
                squareRoot = triplet->squareRoot;

                if (!repeated) {
                    ++count;
                }
            } while (!repeated);

            for (j = 0; j < count; j++) {
                free(triplets[j]);
            }

            if ((count % 2) && count >= maximum) {
                maximum = count;
                answer = i;
            }
        }
    }

    printf("%d", answer);
    
    return 0;
}
