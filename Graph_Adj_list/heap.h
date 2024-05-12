#include "graph.h"

typedef struct heap
{
    Graph **Arr;
    int rear;
    int capacity;
}heap;

void init_heap(heap *h,int c);
void insert(heap *h, Graph *newnode);
void Heapify(heap *h,int i);
Graph* extractMin(heap *h);
void swap(Graph** x, Graph** y);