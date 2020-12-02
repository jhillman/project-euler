/* Problem 61 = 28684 */

#include <stdio.h>
#include "../algorithms.h"

int triangle(int n) {
    return ((n * (n + 1)) / 2);
}

int square(int n) {
    return (n * n);
}

int pentagon(int n) {
    return ((n * (3 * n - 1)) / 2);
}

int hexagon(int n) {
    return (n * (2 * n - 1));
}

int heptagon(int n) {
    return ((n * (5 * n - 3)) / 2);
}

int octagon(int n) {
    return (n * (3 * n - 2));
}

void initialize_polygon_list(struct list *list, int (*polygon)(int)) {
    int n = 1;
    int p = polygon(n++);

    while (p < 10000) {
        if (p > 1000) {
            list_push(list, p);
        }

        p = polygon(n++);
    }
}

long long find_cyclic_sum(struct list **polygons, char *sequence, long long first, long long previous, int index) {
    struct node *polygon = polygons[sequence[index] - '0']->first;
    long long sum = 0;

    while (!sum && polygon) {
        if (index == 5) {
            if (polygon->value / 100 == previous % 100 && first / 100 == polygon->value % 100) {
                sum = polygon->value;
            }
        } else {
            if (index == 0) {
                sum = find_cyclic_sum(polygons, sequence, polygon->value, polygon->value, index + 1);
            } else if (polygon->value / 100 == previous % 100) {
                sum = find_cyclic_sum(polygons, sequence, first, polygon->value, index + 1);
            }

            if (sum) {
                sum += polygon->value;
            }
        }

        polygon = polygon->next;
    }

    return sum;
}

int main() {
    struct list **polygons = (struct list **)calloc(6, sizeof(struct list *));
    char sequence[] = "012345";
    long long answer = 0;
    int i;

    for (i = 0; i < 6; i++) {
        polygons[i] = list_new();

        switch (i) {
        case 0:
            initialize_polygon_list(polygons[i], triangle);
            break;

        case 1:
            initialize_polygon_list(polygons[i], square);
            break;

        case 2:
            initialize_polygon_list(polygons[i], pentagon);
            break;

        case 3:
            initialize_polygon_list(polygons[i], hexagon);
            break;

        case 4:
            initialize_polygon_list(polygons[i], heptagon);
            break;

        case 5:
            initialize_polygon_list(polygons[i], octagon);
            break;
        }
    }

    do {
        answer = find_cyclic_sum(polygons, sequence, 0, 0, 0);
    } while (!answer && next_permutation(sequence, 6));

    for (i = 0; i < 6; i++) {
        free(polygons[i]);
    }

    free(polygons);

    printf("%lld", answer);

    return 0;
}
