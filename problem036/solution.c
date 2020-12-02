/* Problem 36 = 872187 */

#include <stdio.h>
#include <string.h>
#include "../algorithms.h"

int main() {
    long long answer = 0;
    long long palindrome = previous_palindrome(1000000);
    long long decimal;
    char binary[21];
    char reverseBinary[21];
    char *bitPtr;

    while (palindrome > 0) {
        if (palindrome & 1) {
            decimal = palindrome;
            bitPtr = reverseBinary;

            do {
                *bitPtr++ = (decimal & 1) ? '1' : '0';
            } while (decimal >>= 1);

            *bitPtr = 0;
            strcpy(binary, reverseBinary);
            reverse_string(binary);

            if (strcmp(binary, reverseBinary) == 0) {
                answer += palindrome;
            }
        }

        palindrome = previous_palindrome(palindrome);
    }

    printf("%lld", answer);
    
    return 0;
}
