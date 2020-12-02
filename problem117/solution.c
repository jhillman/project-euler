/* Problem 117 = 100808458960497 */

#include <stdio.h>

int main() {
    /* http://mathworld.wolfram.com/TetranacciNumber.html */
    long long first = 1;
    long long second = 1;
    long long third = 2;
    long long fourth = 4;
    long long sum;
    long long answer;
    int i;

    for (i = 0; i < 50; i++) {
        sum = first + second + third + fourth;
        first = second;
        second = third;
        third = fourth;
        fourth = sum;
    }

    answer = first;

    printf("%lld", answer);

    return 0;
}
