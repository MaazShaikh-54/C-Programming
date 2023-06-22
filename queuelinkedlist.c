//queue using linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *addr;
};

struct node *front=NULL, *rear=NULL;

int isEmpty();
void ins(int);
void del();
void show();

int main()
{
	ins(3);//queue: 3
	ins(9);//queue: 3 9
	ins(81);//queue: 3 9 81
	del();//queue: 9 81
	del();//queue: 81
	del();//queue:
	del();//error
}

void ins(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->addr=NULL;
	
	if(isEmpty())
		front=temp;
	else
		rear->addr=temp;
		rear=temp;
	show();
}

int isEmpty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}

void show()
{
	printf("queue: ");
	struct node *i=front;
	while(i!=NULL)
	{
		printf("%d ",i->data);
		i=i->addr;
	}
	printf("\n");
}

void del()
{
	if(isEmpty())
		printf("queue empty error\n");
	else
	{
		struct node *temp=front;
		front=front->addr;
		free(temp);
		if(front==NULL) rear=NULL;
		show();
	}
}