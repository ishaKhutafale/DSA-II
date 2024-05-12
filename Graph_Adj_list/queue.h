typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct queue
{
	node *front,*rear;
}queue;

void init(queue *q);
int isEmpty(queue *q);
void enqueue(queue *q,int data);
int dequeue(queue *q);
void display(queue *q);