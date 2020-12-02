/* Problem 76 = 190569291 */

#include <stdio.h>
#include "../algorithms.h"

int main() {
    int answer = partition(100) - 1;
    
    printf("%d", answer);

    return 0;
}
