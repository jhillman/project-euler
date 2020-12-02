/* Problem 80 = 40886 */

#include <stdio.h>
#include "../list_math.h"
#include <math.h>

int main() {
    int i;
    int j;
    struct list* squareRoot = 0;
    struct list* c = 0;
    int x;
    struct list *x_finder = 0;
    struct list* y = 0;
    char *rootString;
    char *digitPtr;
    int sum;
    int answer = 0;

    for (i = 1; i < 100; i++) {
        if (sqrt(i) != (int)sqrt(i)) {
            squareRoot = list_from_number(0);
            c = list_from_number(0);

            for (j = 0; j < 100; j++) {
                list_multiply_number(c, 100);

                if (j == 0) {
                    list_add_number(c, i);
                }

                x = 0;

                do {
                    ++x;
                    list_free(x_finder);
                    x_finder = list_copy(squareRoot);
                    list_multiply_number(x_finder, 20);
                    list_add_number(x_finder, x);
                    list_multiply_number(x_finder, x);
                } while (list_compare_list(x_finder, c) <= 0);

                list_free(x_finder);
                x_finder = 0;
                --x;
                y = list_copy(squareRoot);
                list_multiply_number(y, 20);
                list_add_number(y, x);
                list_multiply_number(y, x);
                list_multiply_number(squareRoot, 10);
                list_add_number(squareRoot, x);

                if (c->length > 0) {
                    list_subtract_list(c, y);
                }

                list_free(y);
            }

            sum = 0;
            digitPtr = rootString = list_to_string(squareRoot);

            while (*digitPtr) {
                sum += (*(digitPtr++) - '0');
            }

            answer += sum;
            free(rootString);
            list_free(squareRoot);
            list_free(c);
        }
    }

    printf("%d", answer);
    
    return 0;
}
