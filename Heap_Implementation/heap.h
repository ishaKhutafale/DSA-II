typedef struct heap
{
    int *Arr;
    int rear;
    int capacity;
}heap;

void init_heap(heap *h,int c);
void insert(heap *h, int );
void swap(int *x,int *y);
void HeapSort(heap *h);
int extractMin(heap *h);
void Heapify(heap *h,int i);
void deleteKey(heap *h,int i);
void decreaseKey(heap *h,int i,int newvalue);
void print(heap h);