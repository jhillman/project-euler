/* Problem 28 = 669171001 */

#include <stdio.h>

int main() {
    int answer = 1;
    int n;

    for (n = 3; n <= 1001; n += 2) {
        /* top right:    n^2          */
        /* top left:     n^2 -  n + 1 */
        /* bottom left:  n^2 - 2n + 2 */
        /* bottom right: n^2 - 3n + 3 */
        /* total:       4n^2 - 6n + 6 */
        answer += (4 * (n * n)) - (6 * n) + 6;
    }

    printf("%d", answer);
    
    return 0;
}
