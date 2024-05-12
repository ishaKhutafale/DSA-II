#define MAX_SIZE 100
#include <stdbool.h>
typedef struct node
{
    int *Arr;
    int size;
} tree;

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

typedef struct Queue
{
    int front, rear;
    int items[MAX_SIZE];
} Queue;

void init_bst(tree *t, int);
void inorder(tree t);
void preorder(tree t);
void postorder(tree t);
void insert_bst(tree *t, int data);
void levelwiseTraverse(tree t);
int iscomplete(tree t);

int pop(Stack *s);
void push(Stack *s, int value);
int isEmptyStack(Stack *s);
void initialize(Stack *s);

Queue createQueue();
int isEmptyQueue(Queue *queue);
void enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
