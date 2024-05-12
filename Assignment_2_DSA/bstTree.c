#include<stdio.h>
#include<stdlib.h>
#include "bstTree.h"

//bst implementation
void init_bst(tree *t,int size)
{
    t->Arr=(int*)malloc((size)* sizeof(int));
    for (int i = 0; i < size; i++) {
        t->Arr[i] = -1; // Initialize all elements to -1
    }
    t->size=size;
}
void insert_bst(tree *t, int data)
{    
    int pos = 1; 
    while (pos < t->size && t->Arr[pos] != -1) {
        if (data < t->Arr[pos]) {
            pos = 2 * pos; 
        } else if (data > t->Arr[pos]) {
            pos = (2 * pos) + 1; 
        } else {
            printf("Cannot insert duplicate elements in BST.\n");
            return;
        }
    }
    if (pos <= t->size) {
        t->Arr[pos] = data;
    } else {
        printf("Cannot insert. Tree is full.\n");
    }
}
void inorder(tree t) {
    Stack stack;
    initialize(&stack);
    int index = 1; 
    while (index < t.size && t.Arr[index] != -1 || !isEmptyStack(&stack)) {
        while (index < t.size && t.Arr[index] != -1) {
            push(&stack, index);
            index = 2 * index; 
        }

        if (!isEmptyStack(&stack)) {
            index = pop(&stack);
            printf("%d -> ", t.Arr[index]); 
            index = (2 * index) + 1; 
        }
    }
}
void preorder(tree t) {
    Stack stack;
    initialize(&stack);
    int index = 1; 

    push(&stack, index); 

    while (!isEmptyStack(&stack)) {
        index = pop(&stack); 
        printf("%d -> ", t.Arr[index]); 

        if (2 * index + 1 < t.size && t.Arr[2 * index + 1] != -1) {
            push(&stack, 2 * index + 1);
        }
       
        if (2 * index < t.size && t.Arr[2 * index] != -1) {
            push(&stack, 2 * index);
        }
    }
}

void postorder(tree t)
{
    int index = 1;
    Stack s1,s2;
    initialize(&s1);
    initialize(&s2);
    push(&s1,index);
    while (!isEmptyStack(&s1)) {
        index=pop(&s1);
        push(&s2,index);
       if (2 * index < t.size && t.Arr[2 * index] != -1) {
            push(&s1, 2 * index);
        }
         if (2 * index + 1 < t.size && t.Arr[2 * index + 1] != -1) {
            push(&s1, 2 * index + 1);
        }
    }
    while (!isEmptyStack(&s2))
    {
        int index = pop(&s2); 
        printf("%d -> ", t.Arr[index]);
    } 
}
void levelwiseTraverse(tree t) {
    Queue queue = createQueue();
    int index = 1;
    enqueue(&queue, index);

    while (!isEmptyQueue(&queue)) {
        int currentIndex = dequeue(&queue);
        printf("%d ", t.Arr[currentIndex]);

        int leftChildIndex = 2 * currentIndex;
        int rightChildIndex = 2 * currentIndex + 1;

        if (leftChildIndex < t.size && t.Arr[leftChildIndex] != -1) {
            enqueue(&queue, leftChildIndex);
        }
        if (rightChildIndex < t.size && t.Arr[rightChildIndex] != -1) {
            enqueue(&queue, rightChildIndex);
        }
         
    }
    printf("\n");
}

int iscomplete(tree t) {
    if (t.Arr[1] == -1) {
        return 0; // Not complete if the tree is empty
    }

    Queue q= createQueue();
    enqueue(&q, 1);

    while (!isEmptyQueue(&q)) {
        int current = dequeue(&q);

        if (t.Arr[current] != -1) {
            if (2 * current  < t.size) {
                enqueue(&q, 2 * current);
            }

            if (2 * current + 1 < t.size) {
                enqueue(&q, 2 * current + 1);
            }
        } else {
            while (!isEmptyQueue(&q)) {
                int next = dequeue(&q);
                if (t.Arr[next] != -1) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

//stack implementation
void initialize(Stack *s) {
    s->top = -1;
}

int isEmptyStack(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    s->top++;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        int value = s->data[s->top];
        s->top--;
        return value;
    }
}

//queue implementation
Queue createQueue() {
    Queue queue;
    queue.front = -1;
    queue.rear = -1;
    return queue;
}

int isEmptyQueue(Queue *queue) {
    return queue->front == -1;
}

void enqueue(Queue *queue, int item) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}



