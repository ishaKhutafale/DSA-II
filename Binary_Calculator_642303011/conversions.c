#include <stdio.h>
#include "conversions.h"
#include "operations.h"
#include <ctype.h>
#include <stdlib.h>

// Function to determine the precedence of an operator
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(infixExp *infix)
{
    if (infix == NULL)
        return;

    postfixExp *postfix = NULL;
    Stack stack;
    init_stack(&stack);
    while (infix)
    {
        if (isdigit(infix->data))
        {
            pushToPostfix(&postfix, infix->data);
        }
        else if (isOperator(infix->data))
        {
            pushToPostfix(&postfix, '#');
            while (!isEmpty_stack(&stack) && precedence(peekList(&stack)->data) >= precedence(infix->data))
            {
                pushToPostfix(&postfix, popList(&stack)->data);
                pushToPostfix(&postfix, '#');
            }
            pushList(&stack, createNewNode(infix->data));
            // pushToPostfix(&postfix,' ');
        }
        else if (infix->data == '(')
        {
            pushList(&stack, createNewNode(infix->data));
        }
        else if (infix->data == ')')
        {
            while (!isEmpty_stack(&stack) && peekList(&stack)->data != '(')
            {
                pushToPostfix(&postfix, popList(&stack)->data);
            }
            if (!isEmpty_stack(&stack) && peekList(&stack)->data == '(')
            {
                popList(&stack);
            }
        }
        infix = infix->next;
    }

    while (!isEmpty_stack(&stack))
    {
        pushToPostfix(&postfix, popList(&stack)->data);
    }
    evaluatePostfix(postfix);
}

void evaluatePostfix(postfixExp *postfix)
{
    if (postfix == NULL)
    {
        return;
    }

    list temp, l1, l2, rev, tempNode;
    init_list(&l1);
    init_list(&l2);
    init_list(&temp);
    init_list(&tempNode);
    init_list(&rev);
    Stack stack;
    init_stack(&stack);
    while (postfix)
    {
        if (!isOperator(postfix->data))
        {
            if (postfix->data != '#')
            {
                insert_beg(&tempNode, postfix->data);
            }
            else if (postfix->data == '#')
            {
                if (!isEmptyList(&tempNode))
                {
                    pushList(&stack, tempNode);
                }
                pushList(&stack, createNewNode(postfix->data));
                init_list(&tempNode);
            }
        }
        else if (isOperator(postfix->data))
        {
            if (!isEmptyList(&tempNode))
            {
                pushList(&stack, tempNode);
            }
            init_list(&tempNode);
            if (!isEmpty_stack(&stack) && peekList(&stack)->data == '#')
            {
                popList(&stack);
            }
            while (!isEmpty_stack(&stack) && peekList(&stack)->data != '#')
            {
                l2 = popList(&stack);
            }
            if (!isEmpty_stack(&stack))
            {
                popList(&stack);
            }
            while (!isEmpty_stack(&stack) && peekList(&stack)->data != '#')
            {
                l1 = popList(&stack);
            }
            switch (postfix->data)
            {
            case '+':
            {
                temp = addList(l1, l2);
                break;
            }
            case '-':
            {
                temp = subNum(l1, l2);
                break;
            }
            case '*':
            {
                temp = multiply(l1, l2);
                break;
            }
            case '/':
            {
                temp = divide(l1, l2);
                break;
            }
            default:
                break;
            }
            pushList(&stack, temp);
            destroy_list(&l2);
            destroy_list(&l1);
        }
        postfix = postfix->next;
    }
    printf("Answer: \n");
    list l = peekList(&stack);
    rev = reverseList(&l);
    display_list(rev);
}
