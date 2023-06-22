//To implement stack using an array.
#include<stdio.h>
#define SIZE 3

int stack[SIZE]; 
int stackTop=-1;

int isEmpty();
int isFull();
void push(int);
void pop();
int peek();
void show();

int main()
{
	push(10); //stack: 10
	push(20); //stack: 10 20
	printf("stack top = %d\n",peek()); //stack top = 20
	push(15); //stack: 10 20 15
	push(30); //stack full error
	pop(); //stack:  10 20
	pop(); //stack: 10
	pop(); //stack: 
	pop(); //stack empty error
}

int isEmpty()
{
	if(stackTop==-1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(stackTop==SIZE-1)
		return 1;
	else
		return 0;
}

void show()
{
	printf("stack: ");
	int i;
	for(i=0; i<=stackTop; i++)
	{	
		printf("%d\t",stack[i]); 
	}
	printf("\n");
}

void push(int val)
{
	if(isFull())
		printf("Stack full error\n");
	else
	{
		stackTop++;
		stack[stackTop]=val;
		//stack[++stackTop]=val;
		show();
	}
}

int peek()
{
	if(isEmpty())
		printf("stack empty error\n");
	else
		return stack[stackTop];
}

void pop()
{
	if(isEmpty())
		printf("stack empty error\n");
	else
	{
		stackTop--;
		show();
	}
}