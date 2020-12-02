/* Problem 54 = 376 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct card {
    char value;
    char suit;
};

struct hand {
    struct card cards[5];
};

int value_position(char value) {
    char valueOrder[] = "023456789TJQKA";

    return (int)(strchr(valueOrder, value) - valueOrder);
}

int compare(const void *a, const void *b) {
    const struct card *cardOne = (const struct card *)a;
    const struct card *cardTwo = (const struct card *)b;
    
    return value_position(cardOne->value) - value_position(cardTwo->value);
}

int rank_hand(struct hand hand, char *highCard) {
    int values[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int hasHearts = 0;
    int hasSpades = 0;
    int hasClubs = 0;
    int hasDiamonds = 0;
    int uniqueValues = 0;
    int straight = 0;
    int flush = 0;
    int i;
    int rank = 0;
    *highCard = '0';
    qsort(hand.cards, 5, sizeof(struct card), compare);

    for (i = 0; i < 5; i++) {
        ++values[value_position(hand.cards[i].value)];
        hasHearts   = !hasHearts   ? (hand.cards[i].suit == 'H' ? 1 : 0) : hasHearts;
        hasSpades   = !hasSpades   ? (hand.cards[i].suit == 'S' ? 1 : 0) : hasSpades;
        hasClubs    = !hasClubs    ? (hand.cards[i].suit == 'C' ? 1 : 0) : hasClubs;
        hasDiamonds = !hasDiamonds ? (hand.cards[i].suit == 'D' ? 1 : 0) : hasDiamonds;
    }

    for (i = 0; i < 14; i++) {
        uniqueValues += (values[i] != 0);
    }

    flush = (hasHearts + hasSpades + hasClubs + hasDiamonds == 1);
    straight = (uniqueValues == 5 &&
                value_position(hand.cards[4].value) - value_position(hand.cards[0].value) == 4);

    if (straight && flush && hand.cards[0].value == 'T') { /* royal flush */
        rank = 9;
    } else if (straight && flush) { /* straight flush */
        rank = 8;
    } else if (uniqueValues == 2) {
        for (i = 0; i < 5; i++) {
            if (values[value_position(hand.cards[i].value)] == 4) {   /* four of a kind */
                rank = 7;
                *highCard = hand.cards[i].value;
            } else if (values[value_position(hand.cards[i].value)] == 3) { /* full house */
                rank = 6;
                *highCard = hand.cards[i].value;
            }
        }
    } else if (flush) { /* flush */
        rank = 5;
    } else if (straight) { /* straight */
        rank = 4;
    } else if (uniqueValues == 3) {
        for (i = 0; i < 5; i++) {
            if (values[value_position(hand.cards[i].value)] == 3) {   /* three of a kind */
                rank = 3;
                *highCard = hand.cards[i].value;
            } else if (values[value_position(hand.cards[i].value)] == 2) { /* two pair */
                rank = 2;
                *highCard = value_position(hand.cards[i].value) > value_position(*highCard) ?
                            hand.cards[i].value : *highCard;
            }
        }
    } else if (uniqueValues == 4) { /* one pair */
        rank = 1;

        for (i = 0; i < 5; i++) {
            if (values[value_position(hand.cards[i].value)] == 2) {
                *highCard = hand.cards[i].value;
            }
        }
    } else { /* high card */
        rank = 0;
    }

    if (*highCard == '0') {
        *highCard = hand.cards[4].value;
    }

    return rank;
}

int main() {
    FILE *pokerFile;
    struct hand playerOneHand = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    struct hand playerTwoHand = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int i;
    int j;
    int fscanfResult;
    long long playerOneRank;
    long long playerTwoRank;
    char playerOneHighCard;
    char playerTwoHighCard;
    int answer = 0;
    pokerFile = fopen("poker.txt", "r");

    if (pokerFile) {
        for (i = 0; i < 1000; i++) {
            for (j = 0; j < 5; j++) {
                fscanfResult = fscanf(pokerFile, "%c%c ",
                                      &playerOneHand.cards[j].value, &playerOneHand.cards[j].suit);
            }

            for (j = 0; j < 5; j++) {
                fscanfResult = fscanf(pokerFile, "%c%c ",
                                      &playerTwoHand.cards[j].value, &playerTwoHand.cards[j].suit);
            }

            playerOneRank = rank_hand(playerOneHand, &playerOneHighCard);
            playerTwoRank = rank_hand(playerTwoHand, &playerTwoHighCard);

            while (playerOneRank == playerTwoRank && playerOneHighCard == playerTwoHighCard) {
                for (j = 0; j < 5; j++) {
                    if (playerOneHand.cards[j].value == playerOneHighCard) {
                        playerOneHand.cards[j].value = '0';
                    }

                    if (playerTwoHand.cards[j].value == playerTwoHighCard) {
                        playerTwoHand.cards[j].value = '0';
                    }
                }

                playerOneRank = rank_hand(playerOneHand, &playerOneHighCard);
                playerTwoRank = rank_hand(playerTwoHand, &playerTwoHighCard);
            }

            if (playerOneRank > playerTwoRank ||
                    (playerOneRank == playerTwoRank &&
                     value_position(playerOneHighCard) > value_position(playerTwoHighCard))) {
                ++answer;
            }
        }

        fclose(pokerFile);
        
        printf("%d", answer);
    }

    return 0;
}
