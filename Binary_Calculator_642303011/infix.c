#include <stdio.h>
#include <stdlib.h>
#include "infix.h"
#include <ctype.h>

void insertInfixExp(infixExp **head)
{
    char ch;
    infixExp *temp, *rear = NULL;
    ch = getchar();
    while (ch != '\n')
    {
        temp = (infixExp *)malloc(sizeof(infixExp));
        temp->data = ch;
        temp->next = NULL;
        if ((*head) == NULL)
        {
            *head = temp;
        }
        else
        {
            rear = *head;
            while (rear->next != NULL)
            {
                rear = rear->next;
            }
            rear->next = temp;
        }
        ch = getchar();
    }
}
int checkInfix(infixExp *head)
{
    int operandCount = 0;
    int operatorCount = 0;
    int isOperandInProgress = 0;

    while (head != NULL)
    {
        if (isdigit(head->data))
        {
            if (!isOperandInProgress)
            {
                operandCount++;
                isOperandInProgress = 1;
            }
        }
        else if (head->data == '+' || head->data == '-' || head->data == '*' || head->data == '/')
        {
            operatorCount++;
            isOperandInProgress = 0;
        }
        else
        {
            isOperandInProgress = 0;
        }

        head = head->next;
    }
    if (operatorCount < operandCount && operandCount != 1)
    {
        return 1;
    }
    else if (operandCount == 1 && operatorCount == 0)
    {
        // display_infix(head);
        return 2;
    }
    else
    {
        return 0;
    }
}

void display_infix(infixExp *head)
{
    while (head != NULL)
    {
        printf("%c", head->data);
        head = head->next;
    }
    printf("\n");
}