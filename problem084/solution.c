/* Problem 84 = 101524 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct square {
    char *name;
    int sequence;
    int visits;
    struct square *next;
    struct square *previous;
};

void go_to_square(struct square **current, char *squareName) {
    int nameLength = (int)strlen(squareName);

    while (strncmp((*current)->name, squareName, nameLength) != 0) {
        *current = (*current)->next;
    }
}

void shuffle(char *cards[], int count) {
    int i;
    int random;
    char *temp;

    for (i = 0; i < count - 1; i++) {
        random = (rand() % count - 1) + 1;
        temp = cards[random];
        cards[random] = cards[i];
        cards[i] = temp;
    }
}

int compare(const void *a, const void *b) {
    const struct square **squareOne = (const struct square **)a;
    const struct square **squareTwo = (const struct square **)b;
    return (*squareOne)->visits > (*squareTwo)->visits;
}

int main() {
    char *names[] = { "GO", "A1", "CC1","A2", "T1","R1", "B1", "CH1", "B2", "B3", "JAIL", "C1", "U1", "C2", "C3", "R2", "D1", "CC2", "D2", "D3", "FP", "E1", "CH2", "E2", "E3", "R3", "F1", "F2", "U2", "F3", "G2J", "G1", "G2", "CC3", "G3", "R4", "CH3", "H1", "T2", "H2" };
    struct square *go;
    struct square *current;
    struct square *squares[40];
    char *communityChest[] = { "GO", "JAIL", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    char *chance[] = { "GO", "JAIL", "C1", "E3", "H2", "R1", "R", "R", "U", "Back3", 0, 0, 0, 0, 0, 0 };
    int currentCommunityChest = 0;
    int currentChance = 0;
    int i;
    int j;
    int dieOne;
    int dieTwo;
    int doublesCount = 0;
    int done;
    go = malloc(sizeof(struct square));
    go->name = names[0];
    go->sequence = 0;
    go->visits = 0;
    go->next = malloc(sizeof(struct square));
    go->next->previous = go;
    current = go->next;
    squares[0] = go;

    for (i = 1; i < 40; i++) {
        current->name = names[i];
        current->sequence = i;
        current->visits = 0;
        squares[i] = current;

        if (i < 39) {
            current->next = malloc(sizeof(struct square));
            current->next->previous = current;
            current = current->next;
        }
    }

    current->next = go;
    go->previous = current;
    current = go;
    srand((unsigned int)time(0));
    shuffle(communityChest, 16);
    shuffle(chance, 16);

    for (i = 0; i < 10000000; i++) {
        dieOne = (rand() % 4) + 1;
        dieTwo = (rand() % 4) + 1;

        if (dieOne == dieTwo) {
            ++doublesCount;
        } else {
            doublesCount = 0;
        }

        if (doublesCount == 3) {
            go_to_square(&current, "JAIL");
        } else {
            for (j = 0; j < dieOne + dieTwo; j++) {
                current = current->next;
            }

            done = 0;

            while (!done) {
                done = 1;

                if (strcmp(current->name, "G2J") == 0) {
                    go_to_square(&current, "JAIL");
                } else if (strncmp(current->name, "CC", 2) == 0) {
                    if (communityChest[currentCommunityChest]) {
                        go_to_square(&current, communityChest[currentCommunityChest]);
                    }

                    if (++currentCommunityChest == 16) {
                        currentCommunityChest = 0;
                    }
                } else if (strncmp(current->name, "CH", 2)  == 0) {
                    if (chance[currentChance]) {
                        if (strcmp(chance[currentChance], "Back3") == 0) {
                            for (j = 0; j < 3; j++) {
                                current = current->previous;
                            }

                            done = 0;
                        } else {
                            go_to_square(&current, chance[currentChance]);
                        }
                    }

                    if (++currentChance == 16) {
                        currentChance = 0;
                    }
                }
            }
        }

        if (strcmp(current->name, "JAIL") == 0) {
            doublesCount = 0;
        }

        ++current->visits;
    }

    qsort(squares, 40, sizeof(struct square *), compare);
    
    printf("%02d%02d%02d", squares[39]->sequence, squares[38]->sequence, squares[37]->sequence);

    for (i = 0; i < 40; i++) {
        free(squares[i]);
    }

    return 0;
}
