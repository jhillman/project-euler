/* Problem 118 = 44680 */
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"

#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#include "../algorithms.h"

struct list *get_partitions(int number) {
    struct list *partitions = list_new();
    struct list *partition;
    int *addends = (int *)malloc(number * sizeof(int));
    int i;
    int index;
    int parts;
    int remaining;
    int addend;

    for (i = 0; i < number; i++) {
        addends[i] = 1;
    }

    addends[0] = number;
    parts = 0;
    index = 0;

    while (addends[0] != 1) {
        if (addends[index] == 2) {
            ++parts;
            addends[index] = 1;
            --index;
        } else {
            remaining = addends[index] - 1;
            addend = parts - index + 1;
            addends[index] = remaining;

            while (addend >= remaining) {
                ++index;
                addends[index] = remaining;
                addend = addend - remaining;
            }

            if (addend == 0) {
                parts = index;
            } else {
                parts = index + 1;

                if (addend > 1) {
                    ++index;
                    addends[index] = addend;
                }
            }
        }

        partition = list_new();

        for (i = 0; i <= parts; i++) {
            list_push(partition, addends[i]);
        }

        list_push(partitions, (long)partition);
    }

    free(addends);

    return partitions;
}

int main() {
    struct list *partitions = get_partitions(9);
    struct node *partitionNode;
    struct list *partition;
    struct node *part;
    int partSize;
    char set[] = "123456789";
    int length = (int)strlen(set);
    char number[10];
    int potential;
    char *ptr;
    char *sieve = (char *)calloc(9876543 + 1, sizeof(char));
    int allPrime;
    int last;
    int count = 0;
    int answer = 0;
    sieve_primes(sieve, 9876543 + 1);

    do {
        if (set[8] != '4' && set[8] != '6' && set[8] != '8') {
            partitionNode = partitions->first;

            while (partitionNode) {
                allPrime = 1;
                ptr = set;
                last = 987654321;
                partition = (struct list *)(partitionNode->value);
                part = partition->first;

                while (allPrime && part) {
                    partSize = (int)part->value;
                    strncpy(number, ptr, partSize);
                    number[partSize] = 0;
                    potential = atoi(number);

                    if (last > potential) {
                        if (partSize < 8) {
                            allPrime = !sieve[potential];
                        } else {
                            allPrime = is_prime(potential);
                        }

                        if (allPrime) {
                            last = potential;
                        }

                        ptr += partSize;
                        part = part->next;
                    } else {
                        allPrime = 0;
                    }
                }

                if (allPrime) {
                    ++answer;
                    ++count;
                }

                partitionNode = partitionNode->next;
            }
        }
    } while (next_permutation(set, length));

    partitionNode = partitions->first;

    while (partitionNode) {
        partition = (struct list *)(partitionNode->value);
        list_free(partition);
        partitionNode = partitionNode->next;
    }

    list_free(partitions);
    free(sieve);

    printf("%d", answer);

    return 0;
}
