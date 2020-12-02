#include "list.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define LIST_NUMBER_LENGTH 8

struct list *list_from_number(long long number) {
    struct list *list = list_new();
    long long maximum = (long long)pow(10, LIST_NUMBER_LENGTH);
    long long overflow;

    while (number > maximum) {
        overflow = (number - (number % maximum));
        number -= overflow;
        list_push_front(list, number);
        number = overflow / maximum;
    }

    list_push_front(list, number);

    return list;
}

struct list *list_from_string(char *string) {
    struct list *list = list_new();
    char number[LIST_NUMBER_LENGTH + 1];
    char *numberPtr = string;
    long long stringLength = (long long)strlen(string);
    strncpy(number, string, stringLength % LIST_NUMBER_LENGTH);
    number[stringLength % LIST_NUMBER_LENGTH] = '\0';

    while (numberPtr < (string + stringLength)) {
        if (strlen(number) > 0) {
            list_push(list, (long long)atof(number));
        }

        numberPtr += strlen(number);

        if (numberPtr < (string + stringLength)) {
            strncpy(number, numberPtr, LIST_NUMBER_LENGTH);
            number[LIST_NUMBER_LENGTH] = 0;
        }
    }

    return list;
}

char *list_to_string(struct list *list) {
    struct node *listNode = list->first;
    char *listString = (char *)malloc(list->length * LIST_NUMBER_LENGTH * sizeof(char) + 1);
    char *listStringPtr = listString;

    while (listNode) {
        if (listNode->previous) {
            listStringPtr += sprintf(listStringPtr, "%0*lld", LIST_NUMBER_LENGTH, listNode->value);
        } else {
            listStringPtr += sprintf(listStringPtr, "%lld", listNode->value);
        }

        listNode = listNode->next;
    }

    return listString;
}

int list_compare_list(struct list *first, struct list *second) {
    struct node *firstNode;
    struct node *secondNode;
    int result = 0;

    if (first->length > second->length) {
        result = 1;
    } else if (first->length < second->length) {
        result = -1;
    } else {
        firstNode = first->first;
        secondNode = second->first;

        while (firstNode && secondNode && !result) {
            if (firstNode->value > secondNode->value) {
                result = 1;
            } else if (firstNode->value < secondNode->value) {
                result = -1;
            }

            firstNode = firstNode->next;
            secondNode = secondNode->next;
        }
    }

    return result;
}

int list_compare_number(struct list *list, long long number) {
    long long maximum = (long long)pow(10, LIST_NUMBER_LENGTH);
    struct list *numberList;
    int result = 0;

    if (list->length == 1) {
        if (list->first->value > number) {
            result = 1;
        } else if (list->first->value < number) {
            result = -1;
        }
    } else if (list->length >= 1 && number <= maximum) {
        result = 1;
    } else {
        numberList = list_from_number(number);
        result = list_compare_list(list, numberList);
        list_free(numberList);
    }

    return result;
}

void list_add_list(struct list *list, struct list *addend) {
    long long maximum = (long long)pow(10, LIST_NUMBER_LENGTH);
    struct node *listNode;
    struct node *addendNode;
    long long sum;
    long long carry = 0;

    if (list->length < addend->length) {
        while (list->length != addend->length) {
            list_push_front(list, 0);
        }
    }

    listNode = list->last;
    addendNode = addend->last;

    while (listNode && (addendNode || carry)) {
        sum = listNode->value + carry + (addendNode ? addendNode->value : 0);
        carry = 0;

        if (sum >= maximum) {
            sum -= maximum;
            listNode->value = sum;

            if (!listNode->previous) {
                listNode = list_push_front(list, 1);
            } else {
                carry = 1;
            }
        } else {
            listNode->value = sum;
        }

        listNode = listNode->previous;

        if (addendNode) {
            addendNode = addendNode->previous;
        }
    }

    while (list->first && list->first->value == 0) {
        list_pop_front(list);
    }
}

void list_add_number(struct list *list, long long number) {
    struct list *numberList = list_from_number(number);
    list_add_list(list, numberList);
    list_free(numberList);
}

void list_subtract_list(struct list *subtrahend, struct list *minuend) {
    long long maximum = (long long)pow(10, LIST_NUMBER_LENGTH);
    struct node *subtrahendNode = subtrahend->last;
    struct node *minuendNode = minuend->last;
    struct node *borrowNode;

    while (minuendNode) {
        while (subtrahendNode->value < minuendNode->value) {
            subtrahendNode->value += maximum;
            borrowNode = subtrahendNode->previous;

            if (borrowNode->value == 0) {
                while (borrowNode->value == 0) {
                    borrowNode = borrowNode->previous;
                }

                --borrowNode->value;

                while (borrowNode != subtrahendNode->previous) {
                    borrowNode = borrowNode->next;
                    borrowNode->value = maximum - 1;
                }
            } else {
                --borrowNode->value;
            }
        }

        subtrahendNode->value -= minuendNode->value;
        subtrahendNode = subtrahendNode->previous;
        minuendNode = minuendNode->previous;
    }

    while (subtrahend->first && subtrahend->first->value == 0) {
        list_pop_front(subtrahend);
    }
}

void list_subtract_number(struct list *list, long long number) {
    struct list *numberList = list_from_number(number);
    list_subtract_list(list, numberList);
    list_free(numberList);
}

void list_multiply_number(struct list *list, long long number) {
    long long maximum = (long long)pow(10, LIST_NUMBER_LENGTH);
    struct node *listNode;
    long long product;
    long long overflow;
    long long carry;
    listNode = list->last;
    carry = 0;

    while (listNode) {
        product = ((long long)listNode->value * (long long)number) + carry;
        carry = 0;

        if (product >= maximum) {
            overflow = (product - (product % maximum));
            product -= overflow;
            listNode->value = product;

            if (!listNode->previous) {
                listNode = list_push_front(list, (overflow / maximum));
            } else {
                carry = (overflow / maximum);
            }
        } else {
            listNode->value = product;
        }

        listNode = listNode->previous;
    }

    while (list->first && list->first->value == 0) {
        list_pop_front(list);
    }
}

void list_multiply_list(struct list *multiplier, struct list *multiplicand, struct list **product) {
    long long maximum = (long long)pow(10, LIST_NUMBER_LENGTH);
    struct list *intermediateProduct;
    struct node *multiplicandNode = multiplicand->last;
    int shiftCount = 0;
    int i;

    while (multiplicandNode) {
        if (multiplicandNode->value > 0) {
            intermediateProduct = list_copy(multiplier);

            for (i = 0; i < shiftCount; i++) {
                list_multiply_number(intermediateProduct, maximum);
            }

            list_multiply_number(intermediateProduct, multiplicandNode->value);

            if (!*product) {
                *product = list_copy(intermediateProduct);
            } else {
                list_add_list(*product, intermediateProduct);
            }

            list_free(intermediateProduct);
        }

        multiplicandNode = multiplicandNode->previous;
        ++shiftCount;
    }
}

void list_divide_list(struct list *divisor, struct list *dividend, struct list **quotient, struct list **remainder) {
    struct list *decrementor;
    struct list *incrementor;
    long long position;
    struct list *intermediateQuotient = 0;
    struct list *intermediateRemainder = 0;
    decrementor = list_copy(dividend);
    position = ((divisor->length - 1) * LIST_NUMBER_LENGTH + (long long)floor(log10((double)divisor->first->value)) + 1) -
               ((dividend->length - 1) * LIST_NUMBER_LENGTH + (long long)floor(log10((double)dividend->first->value)) + 1) - 1;
    incrementor = list_from_number(1);

    if (position > 0) {
        while (position--) {
            list_multiply_number(decrementor, 10);
            list_multiply_number(incrementor, 10);
        }
    }

    *remainder = list_copy(divisor);
    *quotient = list_new();
    list_push(*quotient, 0);

    while (list_compare_list(*remainder, decrementor) >= 0) {
        list_add_list(*quotient, incrementor);
        list_subtract_list(*remainder, decrementor);
    }

    list_free(decrementor);
    list_free(incrementor);

    if (list_compare_list(*remainder, dividend) >= 0) {
        list_divide_list(*remainder, dividend, &intermediateQuotient, &intermediateRemainder);
        *remainder = list_copy(intermediateRemainder);
        list_add_list(*quotient, intermediateQuotient);
        list_free(intermediateQuotient);
        list_free(intermediateRemainder);
    }
}

void list_modulus_list(struct list *divisor, struct list *dividend, struct list **modulus) {
    struct list *quotient = 0;
    list_divide_list(divisor, dividend, &quotient, modulus);
    list_free(quotient);
}

void list_factorial(long long number, struct list **factorialList) {
    *factorialList = list_new();
    list_push(*factorialList, number ? number : 1);

    while (--number) {
        list_multiply_number(*factorialList, number);
    }
}

void list_power(long long number, long long power, struct list **powerList) {
    int i;
    *powerList = list_new();
    list_push(*powerList, number);

    for (i = 1; i < power; i++) {
        list_multiply_number(*powerList, number);
    }
}

int list_sqrt(struct list *root, struct list **squareRoot) {
    char *rootString = list_to_string(root);
    char *digitPtr = rootString;
    char digits[3];
    int stringLength = (int)strlen(rootString);
    struct list* c = list_from_number(0);
    int x = 0;
    struct list *x_finder = 0;
    struct list* y = 0;
    int square = 0;
    *squareRoot = list_from_number(0);
    strncpy(digits, rootString, stringLength % 2);
    digits[stringLength % 2] = 0;

    while (digitPtr < (rootString + stringLength)) {
        if (strlen(digits) > 0) {
            list_multiply_number(c, 100);
            list_add_number(c, atoi(digits));
            x = 0;

            do {
                ++x;

                if (x_finder) {
                    list_free(x_finder);
                }

                x_finder = list_copy(*squareRoot);
                list_multiply_number(x_finder, 20);
                list_add_number(x_finder, x);
                list_multiply_number(x_finder, x);
            } while (list_compare_list(x_finder, c) <= 0);

            list_free(x_finder);
            x_finder = 0;
            --x;
            y = list_copy(*squareRoot);
            list_multiply_number(y, 20);
            list_add_number(y, x);
            list_multiply_number(y, x);
            list_multiply_number(*squareRoot, 10);
            list_add_number(*squareRoot, x);

            if (c->length > 0) {
                list_subtract_list(c, y);
            }

            list_free(y);
            y = 0;
        }

        digitPtr += strlen(digits);

        if (digitPtr < (rootString + stringLength)) {
            strncpy(digits, digitPtr, 2);
            digits[2] = 0;
        }
    }

    free(rootString);
    square = (c->length == 0);
    list_free(c);
    list_free(y);
    
    return square;
}

struct list *list_choose(int number, int chosen) {
    struct list *numberFactorial = 0;
    struct list *chosenFactorial = 0;
    struct list *numberMinusChosenFactorial = 0;
    struct list *product = 0;
    struct list *quotient = 0;
    struct list *remainder = 0;

    if (number == chosen) {
        quotient = list_from_number(1);
    } else if (chosen == 0) {
        quotient = list_from_number(0);
    } else {
        list_factorial(number, &numberFactorial);
        list_factorial(chosen, &chosenFactorial);
        list_factorial(number - chosen, &numberMinusChosenFactorial);
        list_multiply_list(chosenFactorial, numberMinusChosenFactorial, &product);
        list_divide_list(numberFactorial, product, &quotient, &remainder);
        list_free(numberFactorial);
        list_free(chosenFactorial);
        list_free(numberMinusChosenFactorial);
        list_free(product);
        list_free(remainder);
    }

    return quotient;
}

long long list_product(struct list *numbers) {
    long long product = 1;
    struct node *number = numbers->first;

    while (number) {
        product *= number->value;
        number = number->next;
    }

    return product;
}

long long list_sum(struct list *numbers) {
    long long sum = 0;
    struct node *number = numbers->first;

    while (number) {
        sum += number->value;
        number = number->next;
    }

    return sum;
}
