/* Problem 103 = 20313839404245 */

#include <stdio.h>
#include <math.h>
#include "../list.h"

int main() {
    struct list *set6 = list_new();
    struct list *set7 = list_new();
    struct node *middleNode;
    struct node *setNode;
    int middle;
    int i;
    char *answer;
    char *charPtr;
    list_push(set6, 11);
    list_push(set6, 18);
    list_push(set6, 19);
    list_push(set6, 20);
    list_push(set6, 22);
    list_push(set6, 25);
    middle = (int)ceil(set6->length / 2);
    middleNode = set6->first;

    for (i = 0; i < middle; i++) {
        middleNode = middleNode->next;
    }

    list_push(set7, middleNode->value);
    setNode = set6->first;

    while (setNode) {
        list_push(set7, setNode->value + middleNode->value);
        setNode = setNode->next;
    }

    setNode = set7->first;
    answer = (char *)malloc(set7->length * 2 * sizeof(char) + 1);
    charPtr = answer;

    while (setNode) {
        charPtr += sprintf(charPtr, "%lld", setNode->value);
        setNode = setNode->next;
    }

    list_free(set6);
    list_free(set7);

    printf("%s", answer);

    free(answer);

    return 0;
}
