/* Problem 19 = 171 */

#include <stdio.h>

int main() {
    int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int leapMonths[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int currentDay = 2; /* Tuesday */
    int year;
    int month;
    int answer = 0;

    for (year = 1901; year <= 2000; year++) {
        for (month = 0; month < 12; month++) {
            if (year % 4 == 0) {
                currentDay += leapMonths[month];
            } else {
                currentDay += months[month];
            }

            if (currentDay % 7 == 0) {
                answer += 1;
            }
        }
    }

    printf("%d", answer);
    
    return 0;
}
