#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void init_list(list *head)
{
    *head=NULL;
    return;
}

node* createNewNode(char data){
    node * nn = (node*) malloc(sizeof(node));
    nn -> data = data;
    nn -> next = NULL;
    return nn;
}
void insert_beg(list *head,char d)
{
	node *newnode;
	newnode=createNewNode(d);
	newnode->next=*head;
	*head=newnode;
	return;
}
void insert_end(list *head,char d)
{
	node *p,*newnode;
	newnode=createNewNode(d);
	if(*head == NULL)
	{
		*head=newnode;
		return;
	}
	p=*head;
	while(p->next != NULL)
	{
		p=p->next;
	}
	p->next=newnode;
	return;
}
void display_list(list head)
{
	node *p=head;
	while(p)
	{
		printf("%c",p->data);
		p=p->next;
	}
	return;	
}
void destroy_list(list *head)
{
	node *p = *head;
	node *q;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	*head=NULL;
}
node* reverseList(list  *head) {
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}
int isEmptyList(list *head) {
    return (head == NULL);
}
list copyList(list original) {
    list copy;
    init_list(&copy);
    while (original != NULL) {
        insert_end(&copy, original->data);
        original = original->next;
    }
    return copy;
}
