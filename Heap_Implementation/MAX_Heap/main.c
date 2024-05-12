#include<stdio.h>
#include<stdlib.h>
#include "maxHeap.h"

int main()
{
    heap h;
    init_heap(&h,50);
    int num;
    printf("Enter integers (Enter non-integer value to stop):\n");
    while(scanf("%d",&num)== 1)
    {
        insert(&h,num);
    }
    print(h);
    printf("\n");
    heapSort(&h);
    return 0;
}