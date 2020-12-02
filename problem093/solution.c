/* Problem 93 = 1258 */

#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

#ifdef max
#undef max
#endif
#define max( x, y ) ( ( x ) > ( y ) ? ( x ) : ( y ) )

struct stack {
    double values[4];
    int count;
};

void stack_push(struct stack *stack, double value) {
    stack->values[stack->count++] = value;
}

double stack_pop(struct stack *stack) {
    return stack->values[--stack->count];
}

void stack_clear(struct stack *stack) {
    stack->count = 0;
}

struct expression {
    char expression[8];
    int a;
    int b;
    int c;
    int d;
    int op1;
    int op2;
    int op3;
};

int evaluate_next(struct stack *stack, char *token) {
    int valid = 1;

    switch (*token) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            stack_push(stack, *token - '0');
            break;
        }

        case '+':
        case '-':
        case '*':
        case '/': {
            if (stack->count > 1) {
                switch (*token) {
                case '+':
                    stack_push(stack, stack_pop(stack) + stack_pop(stack));
                    break;

                case '-':
                    stack_push(stack, stack_pop(stack) - stack_pop(stack));
                    break;

                case '*':
                    stack_push(stack, stack_pop(stack) * stack_pop(stack));
                    break;

                case '/':
                    stack_push(stack, stack_pop(stack) / stack_pop(stack));
                    break;
                }
            } else {
                valid = 0;
            }

            break;
        }
    }

    return valid;
}

int main() {
    char expressionString[8];
    int length;
    char *token;
    int valid;
    struct stack *stack = (struct stack *)calloc(1, sizeof(struct stack));
    struct expression expressions[114];
    int expressionCount = 0;
    struct expression *expression;
    int a;
    int b;
    int c;
    int d;
    int e;
    int op1;
    int op2;
    int op3;
    char operators[] = "+-*/";
    double result;
    int *results;
    int maximumResult;
    int consecutive;
    int maximumConsecutive = 0;
    int i;
    int answer = 0;
    strcpy(expressionString, "1234***");
    length = (int)strlen(expressionString);

    do {
        stack_clear(stack);
        token = expressionString;
        valid = 1;

        while (valid && *token) {
            valid = evaluate_next(stack, token);
            ++token;
        }

        if (valid) {
            strcpy(expressions[expressionCount].expression, expressionString);
            expressions[expressionCount].a = (int)(strchr(expressionString, '1') - expressionString);
            expressions[expressionCount].b = (int)(strchr(expressionString, '2') - expressionString);
            expressions[expressionCount].c = (int)(strchr(expressionString, '3') - expressionString);
            expressions[expressionCount].d = (int)(strchr(expressionString, '4') - expressionString);
            expressions[expressionCount].op1 = (int)(strchr(expressionString, '*') - expressionString);
            expressions[expressionCount].op2 = (int)(strchr(expressionString + expressions[expressionCount].op1 + 1, '*') - expressionString);
            expressions[expressionCount].op3 = (int)(strchr(expressionString + expressions[expressionCount].op2 + 1, '*') - expressionString);
            ++expressionCount;
        }
    } while (next_permutation(expressionString, length));

    for (a = 0; a <= 9; a++) {
        for (b = a + 1; b <= 9; b++) {
            for (c = b + 1; c <= 9; c++) {
                for (d = c + 1; d <= 9; d++) {
                    results = (int *)calloc(3025, sizeof(int));
                    maximumResult = 0;

                    for (e = 0; e < expressionCount; e++) {
                        expression = &expressions[e];
                        strcpy(expressionString, expression->expression);
                        expressionString[expression->a] = (char)('0' + a);
                        expressionString[expression->b] = (char)('0' + b);
                        expressionString[expression->c] = (char)('0' + c);
                        expressionString[expression->d] = (char)('0' + d);

                        for (op1 = 0; op1 < 4; op1++) {
                            for (op2 = 0; op2 < 4; op2++) {
                                for (op3 = 0; op3 < 4; op3++) {
                                    expressionString[expression->op1] = operators[op1];
                                    expressionString[expression->op2] = operators[op2];
                                    expressionString[expression->op3] = operators[op3];
                                    token = expressionString;
                                    stack_clear(stack);

                                    while (*token) {
                                        evaluate_next(stack, token++);
                                    }

                                    result = stack_pop(stack);

                                    if (result > 0 && result == (int)result) {
                                        maximumResult = max(maximumResult, (int)result);
                                        results[(int)result] = 1;
                                    }
                                }
                            }
                        }
                    }

                    consecutive = 1;

                    for (i = 1; consecutive && i < maximumResult; i++) {
                        consecutive = results[i];
                    }

                    if (i > maximumConsecutive) {
                        maximumConsecutive = i;
                        answer = a * 1000 + b * 100 + c * 10 + d;
                    }

                    free(results);
                }
            }
        }
    }

    free(stack);
   
    printf("%d", answer);
   
    return 0;
}
