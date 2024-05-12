#ifndef LIST_H
#define LIST_H

#include "list.h"

#endif
typedef struct StackNode {
    list l;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

void init_stack(Stack *);
int isEmpty_stack(Stack* );
void pushList(Stack* ,list);
list popList(Stack *);
list peekList(Stack*);
void display_stack(Stack* stack);
