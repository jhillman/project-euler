/* Problem 122 = 1582 */
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include "../list.h"

struct tree_node {
    int value;
    int layer;
    struct tree_node *parent;
    struct list *children;
};

struct tree_node *tree_add_child(struct tree_node *tree_node, int value, struct tree_node *parent, int layer) {
    struct tree_node *child = (struct tree_node *)calloc(1, sizeof(struct tree_node));
    child->value = value;
    child->layer = layer;
    child->parent = parent;

    if (!tree_node->children) {
        tree_node->children = list_new();
    }

    list_push(tree_node->children, (long)child);

    return child;
}

void tree_free(struct tree_node *tree_node) {
    struct node *childNode;

    if (tree_node->children) {
        childNode = tree_node->children->first;

        while (childNode) {
            tree_free((struct tree_node *)childNode->value);
            free((struct tree_node *)childNode->value);
            childNode = childNode->next;
        }
    }

    list_free(tree_node->children);
}

void tree_expand(struct tree_node *node, int *minimal_addition_chains, int count, int maximum) {
    struct tree_node *current;
    struct tree_node *child;
    int value;

    if (count < maximum) {
        current = node;
        value = current->value;

        while (current) {
            if (current->value + value <= maximum &&
                    !(minimal_addition_chains[current->value + value] && minimal_addition_chains[current->value + value] < node->layer + 1)) {
                child = tree_add_child(node, current->value + value, node, node->layer + 1);
                minimal_addition_chains[current->value + value] = node->layer + 1;
                ++count;
                tree_expand(child, minimal_addition_chains, count, maximum);
            }

            current = current->parent;
        }
    }
}

int main() {
    int maximum = 200;
    struct tree_node *tree = (struct tree_node *)calloc(1, sizeof(struct tree_node));
    int *minimal_addition_chains = (int *)calloc(maximum + 1, sizeof(int));
    int count = 0;
    int i;
    int answer = 0;
    tree->value = 1;
    tree->layer = 0;
    tree_expand(tree, minimal_addition_chains, count, maximum);

    for (i = 0; i <= maximum; i++) {
        answer += minimal_addition_chains[i];
    }

    free(minimal_addition_chains);
    tree_free(tree);

    printf("%d", answer);

    return 0;
}
