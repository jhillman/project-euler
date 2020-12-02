/* Problem 116 = 20492570929 */

#include <stdio.h>
#include "../list_math.h"

struct list *get_placements(int units, int blocks) {
    int remaining;
    int filler;
    struct list *combinations = 0;
    struct list *placements = list_from_number(0);

    for (remaining = 1; remaining <= units / blocks; remaining++) {
        filler = units - remaining * blocks;
        combinations = list_choose(remaining + filler, remaining);
        list_add_list(placements, combinations);
        list_free(combinations);
    }

    return placements;
}

int main() {
    struct list *red = get_placements(50, 2);
    struct list *green = get_placements(50, 3);
    struct list *blue = get_placements(50, 4);
    struct list *answer = list_from_number(0);
    char *answerString;
    list_add_list(answer, red);
    list_add_list(answer, green);
    list_add_list(answer, blue);
    answerString = list_to_string(answer);
    list_free(red);
    list_free(green);
    list_free(blue);
    list_free(answer);

    printf("%s", answerString);

    free(answerString);

    return 0;
}
