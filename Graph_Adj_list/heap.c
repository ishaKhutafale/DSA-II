#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

void init_heap(heap* h, int c) {
    h->Arr = (Graph**)malloc(c * sizeof(Graph*));
    h->rear = -1;
    h->capacity = c;
}

void insert(heap *h, Graph *newnode) {
    if (h->rear == h->capacity - 1)
        return;
    h->rear++;
    int i = h->rear;
    h->Arr[i] = newnode;
    while (i != 0 && h->Arr[(i - 1) / 2]->weight > newnode->weight) {
        h->Arr[i] = h->Arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->Arr[i] = newnode; // Set the correct position for the new node
}


void swap(Graph** x, Graph** y) {
    Graph* temp = *x;
    *x = *y;
    *y = temp;
}

void Heapify(heap *h,int i)
{
    int left=(i*2)+1;
    int right=(i*2)+2;
    int smallest=i;
    if(left <= h->rear && h->Arr[left]->weight < h->Arr[i]->weight)
     {  smallest=left;}
    if(right <= h->rear && h->Arr[right]->weight < h->Arr[smallest]->weight)
     {   smallest=right; }
    if(smallest!=i)
    {
        swap(&h->Arr[i],&h->Arr[smallest]);
        Heapify(h,smallest);
    }
}

Graph* extractMin(heap *h)
{
    if(h->rear < 0)
    {
        return NULL;
    }
        Graph* root=h->Arr[0];
        h->Arr[0]=h->Arr[h->rear];
        h->rear--;
        Heapify(h,0);
        return root;  
}