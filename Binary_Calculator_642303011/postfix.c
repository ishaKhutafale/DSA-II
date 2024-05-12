#include<stdio.h>
#include "postfix.h"
#include<stdlib.h>

void pushToPostfix(postfixExp** postfix, char data) {
    postfixExp* newExp = (postfixExp*)malloc(sizeof(postfixExp));
    if (newExp) {
        newExp->data = data;
        newExp->next = NULL;

        if (*postfix == NULL) {
            // If the list is empty, make the new node the head
            *postfix = newExp;
        } else {
            // Traverse the list to find the last node
            postfixExp* p = *postfix;
            while (p->next != NULL) {
                p = p->next;
            }

            // Append the new node to the end
            p->next = newExp;
        }
    } else {
       
        exit(EXIT_FAILURE);  // or handle the failure appropriately
    }
}

void display_postfix(postfixExp *head)
{
     while (head != NULL)
    {
        printf("%c", head->data);
        head = head->next;
    }
    printf("\n");

}