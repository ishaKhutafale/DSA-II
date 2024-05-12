#include "infix.h"
#include "postfix.h"
#include "StackOfList.h"

int precedence(char c);
int isOperator(char c);
void infixToPostfix(infixExp* infix);
void evaluatePostfix(postfixExp* postfix);
