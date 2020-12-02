/* Problem 191 = 1918080160 */

#include <stdio.h>
#include <string.h>

long long cache[31][4][2];

long long prize(int days, int absent, int late) {
    long long result = cache[days][absent][late];

    if (!result) {
        result = (days == 0);
    }

    if (!result) {
        result = prize(days - 1, 0, late);

        if (late == 0) {
            result += prize(days - 1, 0, 1);
        }

        if (absent <= 1) {
            result += prize(days - 1, absent + 1, late);
        }

        cache[days][absent][late] = result;
    }

    return result;
}

int main() {
    long long answer = 0;
    memset(cache, 0, sizeof(cache));
    answer = prize(30, 0, 0);

    printf("%lld", answer);
    
    return 0;
}