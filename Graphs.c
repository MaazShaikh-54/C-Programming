#include<stdio.h>
#include<stdlib.h>
#define unknown 0
#define known 1
#define visited 2

int main()
{
	int n;
	printf("Number of vertices in graph:");
	scanf("%d",&n);//how many vertices in directed graph?
	
	int a[n+1][n+1];//define the adjacency matrix
	int i,j;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
			a[i][j]=0;//intialize with zeroes
	}
	
	char ch='y';
	int x,y;
	do{
		printf("Add edge? y/n:");//read an edge(x,y)
		ch=getchar();
		if(ch=='y' || ch=='Y')
		{
			printf("\nFrom vertex:");
			scanf("%d",&x);
			printf("To vertex:");
			scanf("%d",&y);
			a[x][y]=1;//make edge(x,y) in adjacency matrix as 1
		}
	}while(ch=='y');
	printf("\n");
	
	//print the adjacency matrix
	printf("\nAdjacency matrix:\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	
	int q[n+1];//a queue data structure to hold known not visited vertices
	int p=-1;//a rear pointer for above queue, initially empty
	
	int state[n+1];//an array to hold the status of all vertices (unknown univisted, known not visited, known visited)
	for(i=1; i<=n; i++)
	{
		state[i]=unknown;//intially all the vertices are unknown univisted
	}
	
	printf("\nstart vertex for BFS:");
	scanf("%d",&x);//start of BFS path
	
	q[++p]=x;//add x in queue (intial front of the queue)
	state[x]=known;//mark it as known vertex
	
	printf("\nBFS path: ");
	while(p!=-1)//till queue is not empty
	{
		state[q[0]]=visited;//mark the front of queue as visited
		for(i=1; i<=n; i++)
		{
			if(a[q[0]][i]==1 && state[i]==unknown)//and its adjacent unknown neighbor
			{
				q[++p]=i;//added in queue
				state[i]=known;//and mark as known
			}
		}
		printf("%d\t",q[0]);//remove front vertex from queue
		for(i=0; i<p; i++)//by left shifting array
			q[i]=q[i+1];
		p--;//and reducing rear pointer
	}
}