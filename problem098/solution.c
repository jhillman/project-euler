/* Problem 98 = 18769 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "../list.h"
#include "../algorithms.h"

#ifdef max
#undef max
#endif
#define max( x, y ) ( ( x ) > ( y ) ? ( x ) : ( y ) )

int *letter_count(char *word) {
    int *letterCounts = (int *)calloc(26, sizeof(int));

    while (*word) {
        ++letterCounts[*word - 'A'];
        ++word;
    }

    return letterCounts;
}

int unique_letters(char *word) {
    int *letterCounts = letter_count(word);
    int letter;
    int unique = 0;

    for (letter = 0; letter < 26; letter++) {
        if (letterCounts[letter]) {
            ++unique;
        }
    }

    free(letterCounts);

    return unique;
}

int *digit_count(char *number) {
    int *digitCounts = (int *)calloc(10, sizeof(int));

    while (*number) {
        ++digitCounts[*number - '0'];
        ++number;
    }

    return digitCounts;
}

int anagrams(char *wordOne, char *wordTwo) {
    int *letterCountOne = letter_count(wordOne);
    int *letterCountTwo = letter_count(wordTwo);
    int letter;
    int anagram = 1;

    for (letter = 0; anagram && letter < 26; letter++) {
        anagram = (letterCountOne[letter] == letterCountTwo[letter]);
    }

    free(letterCountOne);
    free(letterCountTwo);

    return anagram;
}

int unique_digits(char *number) {
    int *digitCounts = digit_count(number);
    int digit;
    int unique = 0;

    for (digit = 0; digit < 10; digit++) {
        if (digitCounts[digit]) {
            ++unique;
        }
    }

    free(digitCounts);

    return unique;
}

char *wordArray[] = {
#include "words.txt"
};

long long squares[10000001];

int main() {
    int count = sizeof(wordArray) / sizeof(char *);
    int *wordLengths = (int *)malloc(count * sizeof(int));
    int *wordLetters = (int *)malloc(count * sizeof(int));
    struct list *anagramList = list_new();
    struct node *anagramNode;
    int i;
    int first;
    int second;
    int pair;
    int minimum;
    int maximum;
    long long number;
    long long square;
    int digits;
    int lastDigits = 0;
    int squareDigits[16];
    char squareString[16];
    char squareWord[16];
    char *digit;
    char *letter;
    char *replace;
    double squareRoot;
    long long answer = 0;

    for (i = 0; i < count; i++) {
        wordLengths[i] = (int)strlen(wordArray[i]);
        wordLetters[i] = unique_letters(wordArray[i]);
    }

    for (number = 1; number <= 10000000; number++) {
        square = number * number;
        squares[number] = square;
        digits = count_digits(square);

        if (digits != lastDigits) {
            squareDigits[digits] = (int)number;
        }

        lastDigits = digits;
    }

    for (first = 0; first < count; first++) {
        for (second = 0; second < count; second++) {
            if (first != second &&
                    wordLengths[first] == wordLengths[second] &&
                    wordLetters[first] == wordLetters[second] &&
                    anagrams(wordArray[first], wordArray[second])) {
                pair = first;
                pair <<= 16;
                pair |= second;
                list_push_front(anagramList, pair);
            }
        }
    }

    anagramNode = anagramList->first;

    while (anagramNode) {
        pair = (int)anagramNode->value;
        second = pair & 0xFFFF;
        pair >>= 16;
        first = pair;
        minimum = squareDigits[wordLengths[first]];
        maximum = squareDigits[wordLengths[first] + 1];

        for (i = minimum; i < maximum; i++) {
            square = squares[i];
            sprintf(squareString, "%lld", square);
            strcpy(squareWord, squareString);

            if (unique_digits(squareString) == wordLetters[first]) {
                digit = squareString;
                letter = wordArray[first];

                while (*digit && *letter) {
                    while ((replace = strchr(squareWord, *digit))) {
                        *replace = *letter;
                    }

                    ++digit;
                    ++letter;
                }

                if (strcmp(wordArray[first], squareWord) == 0) {
                    digit = squareString;
                    letter = wordArray[first];
                    strcpy(squareWord, wordArray[second]);

                    while (*digit && *letter) {
                        while ((replace = strchr(squareWord, *letter))) {
                            *replace = *digit;
                        }

                        ++digit;
                        ++letter;
                    }

                    if (*squareWord != '0') {
                        squareRoot = sqrt(atof(squareWord));

                        if (squareRoot == (int)squareRoot) {
                            answer = max(answer, square);
                        }
                    }
                }
            }
        }

        anagramNode = anagramNode->next;
    }

    list_free(anagramList);
    free(wordLengths);
    free(wordLetters);

    printf("%lld", answer);

    return 0;
}
