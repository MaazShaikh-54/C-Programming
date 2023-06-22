//infix to postfix using stack ADT(Abstract Data type)
//used reusable stack using linked list code
//assuming the infix expression is valid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//stack using linked list
struct node{
	char data;
	struct node *addr;
};//each node contains character data and address of next element in stack

struct node *top=NULL;//stack top, initially null

int isEmpty();//to check is stack empty?
void push(char);//push a value in stack
char pop();//pop and return value of stack top

char in[51];//string to hold infix expression, max size 50 characters + EndOfString character

int main()
{
	printf("Infix: ");
	scanf("%50[^\n]",in);//read the infix expression of max 50 characters
	int n=strlen(in);//find the length of string 50 or less
	//read the infix expression from left to right
	int i=0;
	char c;
	while(i<n)//for each character from infix expression
	{
		c=in[i];//current symbol
		switch(c)//perfrom operation with or without using stack, 
		//low priority operator can not be on top of high priority operator
		{
			case '^':
				while(!isEmpty() && top->data=='^')//till stack top is ^
					printf("%c",pop());//pop and write in postfix
				push(c);//push current character
				break;
			case '/': 
				while(!isEmpty() && (top->data=='^' || top->data=='/'))//till stack top is ^ or /
					printf("%c",pop());//pop and write in postfix
				push(c);//push current character
				break;
			case '*': 
			case '+':
			case '-':
				while(!isEmpty() && (top->data=='^' || top->data=='/' || top->data=='*'))//till stack top is ^ or / or *
					printf("%c",pop());//pop and write in postfix
				push(c);//push current character
				break;
			case '(':
				push(c);//push current character
				break;
			case ')':
				while(!isEmpty() && top->data!='(')//till stack top is not opening brace
					printf("%c",pop());//pop and write in postfix
				pop();//pop and do not write in postfix
				break;
			default:
				printf("%c",c);//write in postfix
		}
		i++;//next character of infix expression
	}
	//at the end of infix expression
	while(!isEmpty())//empty the stack
		printf("%c",pop());//write in postfix expression
}

int isEmpty()//is stack empty?
{
	if(top==NULL)//if top is NULL (initial value)
		return 1;//return true
	else
		return 0;//else return false
}

void push(char x)//push a value in stack
{
	struct node *temp;//create new node 
	temp=(struct node *)malloc(sizeof(struct node));//allocate memory for new node
	temp->data=x;//assign the data part
	temp->addr=top;//attach on top of stack top
	top=temp;//make new node as stack top
}

char pop()//pop a value from stack and return
{
	char x='\0';//default return value is null
	if(!isEmpty())//if stack is not empty
	{
		x=top->data;//then return value is stack top data
		top=top->addr;//make the next value as new stack top
	}
	return x;//return value
}