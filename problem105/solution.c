/* Problem 105 = 73702 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../list_math.h"

int compare_list(const void *a, const void *b) {
    const struct list **one = (const struct list **)a;
    const struct list **two = (const struct list **)b;
    int result = 0;

    if ((*one)->length == (*two)->length) {
        result = (int)((*one)->last->value - (*two)->last->value);
    } else {
        result = ((*one)->length - (*two)->length);
    }

    return result;
}

int power_set(struct list *set, struct list ***pset) {
    int combinations = (int)pow(2, set->length);
    int bits;
    struct node *member;
    int i;
    *pset = (struct list **)calloc(combinations, sizeof(struct list *));

    for (i = 0; i < combinations; i++) {
        bits = i;
        (*pset)[i] = list_new();
        member = set->first;

        while (member && bits) {
            if (bits & 1) {
                list_push((*pset)[i], member->value);
            }

            member = member->next;
            bits >>= 1;
        }
    }

    return combinations;
}

int is_special_sum_set(struct list *set) {
    struct list **pset = 0;
    int combinations;
    int *sums = (int *)calloc((int)list_sum(set) + 1, sizeof(int));
    long long sum;
    long long lastSum = 0;
    int i;
    int special = 1;
    combinations = power_set(set, &pset);

    for (i = 0; special && i < combinations; i++) {
        sum = list_sum(pset[i]);

        if (sums[sum]) {
            special = 0;
        } else {
            sums[sum] = 1;
            list_push(pset[i], sum);
        }
    }

    if (special) {
        qsort(pset, combinations, sizeof(struct list *), compare_list);

        for (i = 0; special && i < combinations; i++) {
            sum = pset[i]->last->value;
        }

        for (i = 0; special && i < combinations; i++) {
            sum = pset[i]->last->value;

            if (sum < lastSum) {
                special = 0;
            }

            lastSum = sum;
        }
    }

    for (i = 0; i < combinations; i++) {
        list_free(pset[i]);
    }

    free(pset);
    free(sums);

    return special;
}

int main() {
    FILE *setFile;
    int i;
    char setString[64];
    char *commaPtr;
    char *memberPtr;
    struct list *set = list_new();
    long long answer = 0;
    setFile = fopen("sets.txt", "r");

    if (setFile) {
        for (i = 0; i < 100; i++) {
            fgets(setString, 64, setFile);
            memberPtr = setString;
            list_clear(set);

            while ((commaPtr = strchr(memberPtr, ','))) {
                *commaPtr = 0;
                list_push(set, atoi(memberPtr));
                memberPtr = commaPtr + 1;
            }

            list_push(set, atoi(memberPtr));

            if (is_special_sum_set(set)) {
                answer += list_sum(set);
            }
        }

        fclose(setFile);
    }

    list_free(set);

    printf("%lld", answer);

    return 0;
}
