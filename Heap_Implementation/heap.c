#include<stdio.h>
#include<stdlib.h>
#include "heap.h"
#include <limits.h>

void init_heap(heap *h,int c)
{
    h->Arr=(int*)malloc(c * sizeof(int));
    h->rear= -1;
    h->capacity=c;
}
void insert(heap *h, int data)
{
    if(h->rear == h->capacity-1)
        return;
    h->rear++;
    int i = h->rear;
    h->Arr[i]= data;
    while(i != 0 && h->Arr[(i-1)/2] > h->Arr[i])
    {
        swap(&h->Arr[i],&h->Arr[(i-1)/2]);
        i = (i-1)/2;
    }
}
void HeapSort(heap *h)
{
    int count=h->rear;
    int temp[count];
    printf("Sorted integers: \n");
    for(int i=0;i<=count;i++)
    {
        temp[i]=extractMin(h);
        printf("%d ",temp[i]);
    }
}
void print(heap h)
{
    printf("Your input integers: \n");
    for(int i=0;i<=h.rear;i++)
    {
        printf("%d ",h.Arr[i]);
    }
}
int extractMin(heap *h)
{
    if(h->rear < 0)
    {
        return -1;
    }
    if(h->rear == 0)
    {
        h->rear--;
        return h->Arr[0];
    }
    
        int root=h->Arr[0];
        h->Arr[0]=h->Arr[h->rear];
        h->rear--;
        Heapify(h,0);
        return root;
    
}
void deleteKey(heap *h,int i)
{
    decreaseKey(h,i,INT_MIN);
    extractMin(h);
}
void decreaseKey(heap *h,int i,int newvalue)
{
    h->Arr[i]=newvalue;
    while(i !=0 && h->Arr[(i-1)/2] > h->Arr[i])
    {
        swap(&h->Arr[i],&h->Arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void Heapify(heap *h,int i)
{
    int left=(i*2)+1;
    int right=(i*2)+2;
    int smallest=i;
    if(left <= h->rear && h->Arr[left] < h->Arr[i])
     {  smallest=left;}
    if(right <= h->rear && h->Arr[right] < h->Arr[smallest])
     {   smallest=right; }
    if(smallest!=i)
    {
        swap(&h->Arr[i],&h->Arr[smallest]);
        Heapify(h,smallest);
    }
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
