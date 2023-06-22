//Graph using matrix
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//G={V,E}
	//read how many vertices in V
	int v;
	printf("How many vertices?");
	scanf("%d",&v);
	
	//define matrix for given graph
	int mat[v][v];
	//intialize matrix to zero
	int i,j;
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
		{
			mat[i][j]=0;
		}
	}
	
	//read edges
	char ch='y';
	int s,e,w,type=1;
	printf("enter 1 for undirected graph or 2 for directed graph\nGraph type:");
	scanf("%d",&type);
	do
	{
		printf("Add edge\nstart vertex:");
		scanf("%d",&s);
		printf("End vertex:");
		scanf("%d",&e);
		printf("weight of an edge:");
		scanf("%d",&w);
		mat[s-1][e-1]=w;
		if(type==1)
			mat[e-1][s-1]=w;
		
		printf("do you want to add more edge?y/n:");
		ch=getchar();
		printf("\n");
	}while(ch=='y' || ch=='Y');
	
	//print matrix for the graph
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}