#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void init(queue *q)
{
	q->front=NULL;
	q->rear=NULL;
	return;
}

int isEmpty(queue *q)
{
	return q->front==NULL;
}

void enqueue(queue *q,int data)
{
	node *nn=(node*)malloc(sizeof(node));
	if(nn)
	{
		nn->data=data;
		nn->next=NULL;
	}
	if(q->front==NULL)
	{
		q->front=nn;
		q->rear=nn;
	}
	else 
	{
		q->rear->next=nn;
		q->rear=nn;
	}
}

int dequeue(queue *q)
{
	if(isEmpty(q))
		return -1;
		
	int data=q->front->data;
	node *temp=q->front;
	q->front=q->front->next;
	
	if (q->front == NULL) 
	{
        	q->rear = NULL;
    	}
	free(temp);
	return data;
	
}

void display(queue *q)
{
	node *temp=q->front;
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
