/* Problem 88 = 7587457 */

#include <stdio.h>
#include "../list_math.h"

#define MAX 12000

int minimals[MAX + 1];

void enumerate(struct list *numbers) {
    long long product = list_product(numbers);
    long long sum = list_sum(numbers);
    long long solution;
    struct list *nextnumbers;
    long long k = numbers->last->value;

    while (product * k < 2 * MAX) {
        solution = numbers->length + 1 + ((product * k) - (sum + k));

        if (solution < MAX && product * k < minimals[solution]) {
            minimals[solution] = (int)(product * k);
        }

        nextnumbers = list_copy(numbers);
        list_push(nextnumbers, k);
        enumerate(nextnumbers);
        list_free(nextnumbers);
        ++k;
    }
}

int main() {
    int i;
    int answer = 0;
    struct list *numbers = list_new();
    int amenables[MAX * 2 + 1];

    for (i = 0; i <= MAX; i++) {
        minimals[i] = 2 * i;
    }

    for (i = 0; i <= MAX * 2; i++) {
        amenables[i] = 0;
    }

    for (i = 2; i < MAX; i++) {
        list_push(numbers, i);
        enumerate(numbers);
        list_clear(numbers);
    }

    list_free(numbers);

    for (i = 2; i < MAX; i++) {
        amenables[minimals[i]] = 1;
    }

    for (i = 2; i <= MAX * 2; i++) {
        if (amenables[i]) {
            answer += i;
        }
    }

    printf("%d", answer);
    
    return 0;
}
