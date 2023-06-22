//evaluate the infix expression
//using reusable C code for stack using linked list
//input: the valid infix expression converted into postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//stack using linked list
struct node{
	double data;
	struct node *addr;
};//each node contains value of variable as data and address of next element in stack
struct node *top=NULL;//stack top, initially null

int isEmpty();//to check if is stack empty?
void push(double);//push a value in stack
double pop();//pop and return value of stack top

char po[51];//string to hold postfix expression, max size 50 characters + EndOfString character

int main()
{
	printf("Postfix: ");
	scanf("%50[^\n]",po);//read the postfix expression of max 50 characters
	int n=strlen(po);//find the length of string 50 or less
	//read the postfix expression from left to right
	int i=0;
	double x,y;//variables to hold operand 1 and operand 2 value, fetched from the stack
	while(i<n)//for each character from postfix expression
	{
		switch(po[i])//perfrom operation with or without using stack, 
		{	
			//note: postfix expression do not have paranthesis, 
			//they are removed while converting from infix to postfix expression
			case '^':
				y=pop();//pop value of second operand
				x=pop();//pop value of first operand
				push(pow(x,y));
				break;
			case '/':
				y=pop();//pop value of second operand
				x=pop();//pop value of first operand
				if(y==0)
					{ printf("Error: divide by zero error\n"); push(-999999999); }
				else
					push(x/y);//perform operation based on the operator and push the result
				break;
			case '*':
				y=pop();//pop value of second operand
				x=pop();//pop value of first operand
				push(x*y);//perform operation based on the operator and push the result
				break;
			case '+':
				y=pop();//pop value of second operand
				x=pop();//pop value of first operand
				push(x+y);//perform operation based on the operator and push the result
				break;
			case '-':
				y=pop();//pop value of second operand
				x=pop();//pop value of first operand
				push(x-y);//perform operation based on the operator and push the result
				break;
			default:
				printf("%c=",po[i]);//read the value for operand
				scanf("%lf",&x);
				push(x);//push the value of operand
		}
		i++;
	}
	//final stack element is answer to the expression evaluation
	printf("Answer: %lf",pop());
}

int isEmpty()//is stack empty?
{
	if(top==NULL)//if top is NULL (initial value)
		return 1;//return true
	else
		return 0;//else return false
}

void push(double x)//push a value in stack
{
	struct node *temp;//create new node 
	temp=(struct node *)malloc(sizeof(struct node));//allocate memory for new node
	temp->data=x;//assign the data part
	temp->addr=top;//attach on top of stack top
	top=temp;//make new node as stack top
}

double pop()//pop a value from stack and return
{
	double x=0.0;//default return value is 0
	if(!isEmpty())//if stack is not empty
	{
		x=top->data;//then return value is stack top data
		top=top->addr;//make the next value as new stack top
	}
	return x;//return value
}