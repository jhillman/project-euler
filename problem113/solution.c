/* Problem 113 = 51161058134250 */

#include <stdio.h>
#include "../list_math.h"

int main() {
    int i;
    struct list *not_bouncy = list_from_number(0);
    struct list *increasing = 0;
    struct list *decreasing = 0;
    char *answer;

    for (i = 1; i <= 100; i++) {
        decreasing = list_choose(8 + i, i);
        increasing = list_choose(9 + i, i);
        list_add_list(not_bouncy, decreasing);
        list_add_list(not_bouncy, increasing);
        list_subtract_number(not_bouncy, 10);
        list_free(decreasing);
        list_free(increasing);
    }

    answer = list_to_string(not_bouncy);

    printf("%s", answer);

    list_free(not_bouncy);
    free(answer);

    return 0;
}
