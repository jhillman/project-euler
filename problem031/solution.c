/* Problem 31 = 73682 */

#include <stdio.h>
#include "../list.h"
#include "../algorithms.h"

int main() {
    struct list *coins = list_new();
    list_push(coins, 1);
    list_push(coins, 2);
    list_push(coins, 5);
    list_push(coins, 10);
    list_push(coins, 20);
    list_push(coins, 50);
    list_push(coins, 100);
    list_push(coins, 200);
    
    printf("%lld", get_combinations(200, coins));
    
    list_free(coins);
    
    return 0;
}
