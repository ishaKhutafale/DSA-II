typedef struct heap
{
    int *Arr;
    int rear;
    int capacity;
}heap;

void init_heap(heap *h,int);
void insert(heap *h,int );
int extractMax(heap *h);
void swap(int *,int *);
void heapSort(heap *h);
void heapify(heap *h,int index);
void print(heap);