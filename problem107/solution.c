/* Problem 107 = 259679 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../list.h"

#define VERTICES 40

struct edge {
    int vertexOne;
    int vertexTwo;
    int weight;
};

int compare(const void *a, const void *b) {
    const struct edge **one = (const struct edge **)a;
    const struct edge **two = (const struct edge **)b;

    return (*one)->weight - (*two)->weight;
}

int main() {
    FILE *networkFile;
    int network[VERTICES][VERTICES];
    int optimizedNetwork[VERTICES][VERTICES];
    int row;
    int column;
    char rowString[256];
    char *commaPtr;
    char *edgePtr;
    struct edge *priorityQueue[VERTICES * VERTICES];
    int count = 0;
    int position = 0;
    struct list *trees[VERTICES];
    struct list *treesInvolved = list_new();
    struct edge *edge;
    int weightBefore = 0;
    int weightAfter = 0;
    int i;
    int answer = 0;
    networkFile = fopen("network.txt", "r");

    if (networkFile) {
        for (row = 0; row < VERTICES; row++) {
            fgets(rowString, 256, networkFile);
            column = 0;
            edgePtr = rowString;

            while ((commaPtr = strchr(edgePtr, ','))) {
                *commaPtr = 0;

                if (strcmp(edgePtr, "-") == 0) {
                    network[row][column] = 0;
                } else {
                    network[row][column] = atoi(edgePtr);
                }

                optimizedNetwork[row][column++] = 0;
                edgePtr = commaPtr + 1;
            }

            if (strcmp(edgePtr, "-") == 0) {
                network[row][column] = 0;
            } else {
                network[row][column] = atoi(edgePtr);
            }

            optimizedNetwork[row][column++] = 0;
        }

        fclose(networkFile);

        for (row = 0; row < VERTICES; row++) {
            for (column = row; column < VERTICES; column++) {
                if (network[row][column]) {
                    priorityQueue[count] = (struct edge *)calloc(1, sizeof(struct edge));
                    priorityQueue[count]->vertexOne = row;
                    priorityQueue[count]->vertexTwo = column;
                    priorityQueue[count]->weight = network[row][column];
                    ++count;
                }
            }
        }

        qsort(priorityQueue, count, sizeof(struct edge *), compare);

        /* http://en.wikipedia.org/wiki/Kruskal_algorithm */

        for (i = 0; i < VERTICES; i++) {
            trees[i] = list_new();
            list_push(trees[i], i);
        }

        while ((*trees)->length < VERTICES) {
            edge = priorityQueue[position++];
            list_clear(treesInvolved);

            for (i = 0; i < VERTICES; i++) {
                if (list_find(trees[i], edge->vertexOne) || list_find(trees[i], edge->vertexTwo)) {
                    list_push(treesInvolved, i);
                }
            }

            if (treesInvolved->length == 2) {
                while (trees[treesInvolved->last->value]->length) {
                    list_push(trees[treesInvolved->first->value], list_pop(trees[treesInvolved->last->value]));
                }

                optimizedNetwork[edge->vertexOne][edge->vertexTwo] = edge->weight;
            }
        }

        for (i = 0; i < count; i++) {
            free(priorityQueue[i]);
        }

        for (i = 0; i < VERTICES; i++) {
            list_free(trees[i]);
        }

        list_free(treesInvolved);

        for (row = 0; row < VERTICES; row++) {
            for (column = row; column < VERTICES; column++) {
                weightBefore += network[row][column];
                weightAfter += optimizedNetwork[row][column];
            }
        }
    }

    answer = weightBefore - weightAfter;

    printf("%d", answer);

    return 0;
}
