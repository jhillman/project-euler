/* Problem 121 = 2269 */

#include <stdio.h>

long long take_turn(long long wins, int blue, int turn, int total_turns) {
    long long win_combinations = 0;

    if (turn > total_turns) {
        if (blue > total_turns / 2) {
            win_combinations = wins;
        }
    } else {
        win_combinations = take_turn(wins, blue + 1, turn + 1, total_turns);
        win_combinations += take_turn(turn * wins, blue, turn + 1, total_turns);
    }

    return win_combinations;
}

long long factorial(int number) {
    long long result = 1;

    if (number > 1) {
        result = number * factorial(number - 1);
    }

    return result;
}

int main() {
    int turns = 15;
    long long all_combinations = factorial(turns + 1);
    long long win_combinations = take_turn(1, 0, 1, turns);
    long long answer = all_combinations / win_combinations;

    printf("%lld", answer);

    return 0;
}
