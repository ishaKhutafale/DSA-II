#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Expression.h"

void init_tree(tree *t)
{
    *t = NULL;
    return;
}
node *createNode(char data)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
void insert(tree *t, char data)
{
    node *p = *t, *q;
    while (p)
    {
        q = p;
        if (data < p->data)
        {
            p = p->left;
        }
        else if (data > p->data)
        {
            p = p->right;
        }
        else
        {
            return;
        }
    }
    if (data < q->data)
    {
        q->left = createNode(data);
    }
    else
    {
        q->right = createNode(data);
    }
}
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
node *constructTree(char exp[])
{
    Stack s1, s2;
    initialize(&s1);
    initialize(&s2);
    node *b, *op1, *op2;
    init_tree(&b);
    init_tree(&op1);
    init_tree(&op2);
    int i = 0;
    char c;
    while ((c = exp[i]) != '\0')
    {
        if (isalnum(c))
        {
            b = createNode(c);
            push(&s2, b);
        }
        else if (c == '(')
        {
            b = createNode(c);
            push(&s1, b);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!isEmpty(&s1) && !isEmpty(&s2) && precedence(peek(&s1)->data) >= precedence(c))
            {
                b = pop(&s1);
                op2 = pop(&s2);
                op1 = pop(&s2);
                b->left = op1;
                b->right = op2;
                push(&s2, b);
            }
            b = createNode(c);
            push(&s1, b);
        }
        else if (c == ')')
        {
            while (!isEmpty(&s1) && peek(&s1)->data != '(')
            {
                b = pop(&s1);
                op2 = pop(&s2);
                op1 = pop(&s2);
                b->left = op1;
                b->right = op2;
                push(&s2, b);
            }
            if (!isEmpty(&s1) && peek(&s1)->data == '(')
            {
                pop(&s1);
            }
        }
        i++;
    }
    b = pop(&s2);
    return b;
}
void inorder(tree t1)
{
    if (t1 == NULL)
    {
        return;
    }
    inorder(t1->left);
    printf("%c ", t1->data);
    inorder(t1->right);
}
int validateInfix(char exp[])
{
    int balance = 0;
    char c;
    int i = 0;
    int operandCount = 0;
    int operatorCount = 0;
    int isOperandInProgress = 0;
    while ((c = exp[i]) != '\0')
    {
        if (isalnum(c))
        {
            if (!isOperandInProgress)
            {
                operandCount++;
                isOperandInProgress = 1;
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            operatorCount++;
            isOperandInProgress = 0;
        }
        else if (c == '(')
        {
            balance++;
        }
        else if (c == ')')
        {
            balance--;
        }
        else
        {
            isOperandInProgress = 0;
        }
        i++;
    }
    if ((operatorCount == 0 && operandCount != 0) || (operatorCount != 0 && operandCount == 0))
    {
        return 0;
    }
    else if (operatorCount < operandCount && operandCount != 1 && balance == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// stack functions
void initialize(Stack *stack)
{
    stack->top = NULL;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, tree value)
{
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    // Update the top to the new node
    stack->top = newNode;
}

tree pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    // Get the value at the top
    // Move the top to the next node
    Node *temp = stack->top;
    tree value = temp->data;
    stack->top = temp->next;
    // Free the memory of the popped node
    free(temp);
    return value;
}
tree peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}
