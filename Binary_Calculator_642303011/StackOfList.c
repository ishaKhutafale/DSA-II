#include<stdio.h>
#include "StackOfList.h"
#include<stdlib.h>

void init_stack(Stack* stack)
{
    stack->top=NULL;
    return;
}
int isEmpty_stack(Stack* stack)
{
    return stack->top == NULL;
}
void pushList(Stack* stack, list l )
{
    if (l == NULL) {
        //printf("cannot push empty list");
        return;  
    }
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
       
       return;
    }
    
    newNode->l = l;
    newNode->next = stack->top;
    stack->top = newNode;
}
list popList(Stack* stack)
{
    if (isEmpty_stack(stack)) {
        
        exit(EXIT_FAILURE);
        //return;
    }
    list value = stack->top->l;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}
list peekList(Stack* stack)
{
    if (isEmpty_stack(stack)) {
        
        exit(EXIT_FAILURE);
        //return;
    }
    list temp=stack->top->l;
    return temp;
}

void display_stack(Stack* stack) {
    if (isEmpty_stack(stack)) {
        return;
    }

   // printf("Stack elements: ");
    StackNode* current = stack->top;
    while (current != NULL) {
        printf("%c", current->l->data);
        current = current->next;
    }
    printf("\n");
}

