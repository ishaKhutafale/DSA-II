#include<stdio.h>
#include<stdlib.h>
#include "maxHeap.h"

void init_heap(heap *h,int c)
{
    h->Arr=(int*)malloc(c * sizeof(int));
    h->rear=-1;
    h->capacity=c;
}
void insert(heap *h,int key)
{
    if(h->rear==h->capacity-1)
    {
        return;
    }
    h->rear++;
    int i=h->rear;
    h->Arr[i]=key;
    while(i != 0 && h->Arr[i] > h->Arr[(i-1)/2] )
    {
        swap(&h->Arr[i],&h->Arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
int extractMax(heap *h)
{
    if(h->rear < 0)
    {
        return -1;
    }
        
    if(h->rear==0)
    {
        h->rear--;
        return h->Arr[0];
    }
    
    int max=h->Arr[0];
    h->Arr[0]=h->Arr[h->rear];
    h->rear--;
    heapify(h,0);
    return max;
}
void heapify(heap *h,int index)
{
    int largest=index;
    int left=(2*index)+1;
    int right=(2*index)+2;

    if(left <= h->rear && h->Arr[left] > h->Arr[index])
     {   largest=left;  }
    if(right <= h->rear && h->Arr[right] > h->Arr[largest])
     {   largest=right;  }
    if(largest!=index)
    {
        swap(&h->Arr[largest],&h->Arr[index]);
        heapify(h,largest);
    }
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void print(heap h)
{
    printf("Your input integers: \n");
    for(int i=0;i<=h.rear;i++)
    {
        printf("%d ",h.Arr[i]);
    }
}
void heapSort(heap *h)
{
    int count=h->rear;
    int temp[count];
    for(int i=0;i<=count;i++)
    {
        temp[i]=extractMax(h);
        printf("%d ",temp[i]);
    }
}