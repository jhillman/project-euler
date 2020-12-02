/* Problem 53 = 4075 */

#include <stdio.h>
#include "../list_math.h"

int main() {
    int answer = 0;
    int number;
    int chosen;
    struct list *chooseList = 0;

    for (number = 1; number <= 100; number++) {
        for (chosen = 1; chosen < number; chosen++) {
            list_free(chooseList);
            chooseList = list_choose(number, chosen);

            if (list_compare_number(chooseList, 1000000) > 0) {
                answer += (number - (2 * chosen)) + 1;
                break;
            }
        }
    }

    list_free(chooseList);

    printf("%d", answer);

    return 0;
}
