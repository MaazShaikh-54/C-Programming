/* linear search
10 50 20 30 40 35 ... N
total elements: N
no of comparision: N
best case 10? 1
worst case N?  O(N)*/

/* binary search
data = {10 50 20 30 40 35 55 }
data_sorted = {10 20 30 35 40 50 55}
search for 70? (worst case)
70 > 35
70 > 50
70 > 55
total elements: 7 (N)
no of comparision: 3 O(log N to the base 2)
*/

/* BST
left subtree <= Parent < right subtree
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left, *right;
};
struct node *root=NULL;

int isEmpty();
void ins(int);
void show(struct node *, char, int);

int main()
{
	ins(10);
	ins(5);
	ins(20);
	ins(3);
	ins(7);
	ins(30);
	ins(500);
	ins(0);
	ins(46);
}

int isEmpty()
{
	if(root==NULL)
		return 1;
	else
		return 0;
}

void ins(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	
	if(isEmpty())
	{
		root=temp;
	}
	else
	{
		struct node *prev=NULL, *cur=root;
		while(cur!=NULL)
		{
			prev=cur;
			if(val <= cur->data)
				cur=cur->left;
			else
				cur=cur->right;
		}
		if(val <= prev->data)
			prev->left=temp;
		else
			prev->right=temp;
	}
	printf("********** insert(%d)*******************\n",val);
	show(root,'X',0);
	printf("\n");
}

void show(struct node *i, char type, int level)
{
	int j;
	for(j=1; j<=level; j++)
	 	printf("\t");
	 	
	printf("%d ",i->data);
	
	if(type=='l')
		printf("(L)\n");
	else if(type=='r')
		printf("(R)\n");
	else
		printf("root\n");
		
	if(i->left!=NULL) show(i->left, 'l', level+1);
	if(i->right!=NULL) show(i->right, 'r', level+1);	
}
