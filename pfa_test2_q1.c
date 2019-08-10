#include<stdio.h>
#include<malloc.h>

struct queuenode 
{
	int data;
	struct queuenode * next;

};
typedef struct queuenode node;
node *start=NULL,*end=NULL;
void enQueue(int data)
{
	node * newnode;
	newnode=(node *)malloc(sizeof(node));
	newnode->next=NULL;
	newnode->data=data;
	if(start==NULL)
	{
		start=newnode;
		end=newnode;

	}
	else
	{
		end->next=newnode;
		end=newnode;

	}
}

void deQueue()
{
	int data;
	if(start!=NULL)
	{
		printf("\nDequeue element is %d",start->data);
		start=start->next;
	}	
	else
	{
		printf("\nNothing to dequeue");
	}
}
void peek()
{
	if(start!=NULL)
	printf("\nThe peek element is %d",start->data);
	else 
	printf("\nQueue is empty");

}
void main()
{
	
	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	peek();
	deQueue();
	peek();
	deQueue();
	peek();
	deQueue();
	peek();
	deQueue();
	peek();
	deQueue();	
}
