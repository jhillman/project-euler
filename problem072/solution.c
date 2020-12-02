/* Problem 72 = 303963552391 */

#include <stdio.h>
#include "../algorithms.h"

long long totients[1000000 + 1];

int main() {
    int n;
    int k;
    long long answer = 0;

    for (n = 0; n <= 1000000; n++) {
        totients[n] = n;
    }

    for (n = 2; n <= 1000000; n++) {
        if (totients[n] == n) {
            for (k = n; k <= 1000000; k += n) {
                totients[k] *= (n - 1);
                totients[k] /= n;
            }
        }

        answer += totients[n];
    }

    printf("%lld", answer);
    
    return 0;
}
