//Josephus problem using Circular linked list
//what is Josephus problem?
/*
1. There are n people standing in a circle waiting to be executed. 
2. The counting out begins at some point in the circle (start of CLL) and 
	proceeds around the circle in a fixed direction.
3. In each step, k-1 number of people are skipped and the next person is executed. 
4. The elimination proceeds around the circle 
	(which is becoming smaller and smaller as the executed people are removed), 
	until only the last person remains, who is given freedom.
5. The task is to choose the place in the initial circle 
	so that you are the last one remaining and so survive.
6. Input: n number of persons,
		every time k-1 people are skipped and kth will be executed
7. Output: the rank of the person who is safe
*/
#include<stdio.h>
#include<stdlib.h>

struct node{//each node contains
	int data;//data part
	struct node *addr;//address of the next node
};//last node holds the addr of first node

//special pointer which holds the address of first node of the list, initially NULL
struct node *start=NULL;

int is_empty();//is linked list empty? return true/ false
void ins(int);//insert new value at particular location of new node
void del(int);//delete first instance of node with specified value, else error
void show();//display contain of the list

int main()
{
	int n;
	printf("n:");
	scanf("%d",&n);
	
	int k;
	printf("k:");
	scanf("%d",&k);
	
	int i=1;
	while(i<=n)
		ins(i++);
		
	struct node *cur=start, *temp;
	while(n!=1)
	{
		for(i=1; i<k; i++)
		{
			cur=cur->addr;
		}
		temp=cur;
		cur=cur->addr;
		printf("Killed:%d\t",temp->data);
		del(temp->data);
		printf("Alive:"); show();
		n--;
	}
	printf("\nSafe rank:%d",start->data);
}

int is_empty()
{
	if(start==NULL)//if start is null
		return 1;//return true
	else
		return 0;//else return false
}

void ins(int x)//assuming linked list stores data in increasing order of node data
{
	struct node *cur, *prev,*i;
	struct node *temp;//create new node pointer
	temp = (struct node *)malloc(sizeof(struct node));//allocate memory of node size and get the memory location
	temp->data=x;//store data value in new node
	temp->addr=NULL;//make addr part as null for new node
	if(is_empty())//if linked list is empty
	{
		start=temp;//make new node as start node, i.e. new node is first node of the list
		temp->addr=start;//since it is only node of linked list, it points to itself
	}
	else//for non first node
	{
		//traverse the linked list from first node till last node of the list
		cur=start;//initially current node is start i.e. first node of the list
		prev=NULL;//initially previous node is null as no previous node to the first node
		do{//traverse to find position for new node
			if(cur->data <= x)//if current node is less than or equal to new node value
			{
				prev=cur;//make current node as previous node
				cur=cur->addr;//and next node as current, i.e. move to the next node
			}
			else
				break;//found a position for new node? stop searching
		}while(cur!=start);
		if(prev==NULL)//if new node to be inserted as first node 
		{
			temp->addr=cur;//new node points to first node
			start=temp;//new node becomes first node
			//cur holds address of previous start address
			//traverse till last node, whose address part was cur
			i=cur;
			while(i->addr!=cur)
			{
				i=i->addr;
			}
			//update its address part with new start value	
			i->addr = start;
		}
		else//for all other cases (new node in between or as last node of the list)
		{
			temp->addr=cur;//new node points to current node
			prev->addr=temp;//previous node points to new node
		}
	}
}

void del(int x)
{
	//traverse the linked list from first node till last node of the list
	//initially current node is start i.e. first node of the list
	//initially previous node is null as no previous node to the first node
	struct node *prev=NULL, *cur=start,*i;
	if(is_empty())//if linked list is empty?
	{
		printf("Error: list is empty\n");//true, show error
	}
	else//false, traverse to find node with value to delete or to reach till end of the list
	{
		while(cur->data!=x)
		{//stop searching if node to delete is found or no more nodes to compare
			prev=cur;//else make current node as previous
			cur=cur->addr;//and next node as current, i.e. move to the next node
			if(cur==start)//if linked list contains only one node, and that too not matching with required value
			{
				cur=NULL;//make current null to indicate above case
				break;//then stop searching
			}
		}
		if(cur==NULL)//traversed all nodes but could not find a node with value to delete
		{
			printf("Error: no such node with value %d to delete\n",x);//show error
		}	
		else//node found
		{
			if(cur->addr==start && prev==NULL)//if node to delete is only node of the list
				start=NULL;
			else if(cur==start)//if node to delete is first node
			{
				start=start->addr;//update start as second node of the list, in case of of only node start turns null
				//last node should be updated with updated start value
				i=start;//starting from first node
				while(i->addr!=cur)//traverse till last node (whose address part is previous value of start)
					i=i->addr;
				i->addr=start;//update its address part with new start value
			}
			else//if node to delete is non first node, non single node
			{
				prev->addr=cur->addr;//update the address part of previous node as next of node to delete
				//in case of deletion of last node
				//new last node should hold the address of first node, since circular linked list
				if(prev->addr==NULL)
					prev->addr=start;
			}
		}
	}
}

void show()
{
	struct node *i=start;
	do
	{
		printf("%d ",i->data);
		i=i->addr;
	}while(i!=start);
	printf("\n");
}