/* Problem 43 = 16695334890 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../algorithms.h"

int main() {
    char pandigital[] = "0123456789";
    char *piecePtr;
    char pieceString[11];
    int piece;
    int length = strlen(pandigital);
    int primes[] = { 2, 3, 5, 7, 11, 13, 17 };
    int primeIndex;
    int subStringDivisable;
    int subStringLength = 3;
    long long answer = 0;

    do {
        subStringDivisable = 1;
        primeIndex = 0;
        piecePtr = pandigital + (length % subStringLength);

        while (subStringDivisable && primeIndex < 7) {
            piece = atoi(strncpy(pieceString, piecePtr, subStringLength));

            if (piece % primes[primeIndex]) {
                subStringDivisable = 0;
            }

            ++primeIndex;
            piecePtr++;
        }

        if (subStringDivisable) {
            answer += (long long)atof(pandigital);
        }
    } while (next_permutation(pandigital, length));

    printf("%lld", answer);
    
    return 0;
}
