/* Problem 127 = 15377700 */

#include <stdio.h>
#include "../algorithms.h"
#include "../list_math.h"

struct radical_info {
    int n;
    int radical;
};

int compare_radical_info(const void *a, const void *b) {
    int result = (*(struct radical_info *)a).radical - (*(struct radical_info *)b).radical;

    if (result == 0) {
        result = (*(struct radical_info *)a).n - (*(struct radical_info *)b).n;
    }

    return result;
}

int radical(int n) {
    struct list *factors = prime_factors(n);
    int radical = (int)list_product(factors);

    list_free(factors);

    return radical;
}

long long radicals[110000];
struct radical_info radicalInfos[110000] = { 0, 0 };

int main() {
    int a;
    int b;
    int c;
    int n;
    int maximum;
    int i;
    int answer = 0;

    for (n = 0; n < 110000; n++) {
        radicals[n] = radical(n);
        radicalInfos[n].n = n;
        radicalInfos[n].radical = (int)radicals[n];
    }

    qsort(radicalInfos, 110000, sizeof(struct radical_info), compare_radical_info);

    for (c = 1; c < 110000; c++) {
        maximum = c / (int)radicals[c];

        for (i = 1; radicalInfos[i].radical < maximum; i++) {
            a = radicalInfos[i].n;
            b = c - a;

            if (b > a && radicals[a] * radicals[b] < maximum) {
                if (gcd(a, b) == 1) {
                    answer += c;
                }
            }
        }
    }

    printf("%d", answer);

    return 0;
}
