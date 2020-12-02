/* Problem 74 = 402 */

#include <stdio.h>
#include "../list_math.h"

int main() {
    int factorials[10] = { 1 };
    int *chains;
    int number;
    struct list *chain = 0;
    int sum;
    int length;
    struct node *link;
    char numberString[100];
    char *digitPtr;
    int answer = 0;

    for (number = 1; number < 10; number++) {
        factorials[number] = number * factorials[number - 1];
    }

    chains = (int *)calloc(6 * factorials[9] + 1, sizeof(int));

    for (number = 1; number < 1000000; number++) {
        chain = list_from_number(number);
        length = 0;

        while (1) {
            if (chains[chain->last->value]) {
                length += chains[chain->last->value];
                break;
            } else {
                ++length;
                sum = 0;
                sprintf(numberString, "%lld", chain->last->value);
                digitPtr = numberString;

                while (*digitPtr) {
                    sum += factorials[*digitPtr++ - '0'];
                }

                if (list_find(chain, sum)) {
                    break;
                } else {
                    list_push(chain, sum);
                }
            }
        }

        if (length == 60) {
            ++answer;
        }

        link = chain->first;

        while (link) {
            chains[link->value] = length--;
            link = link->next;
        }

        list_free(chain);
    }

    free(chains);
   
    printf("%d", answer);
   
    return 0;
}
