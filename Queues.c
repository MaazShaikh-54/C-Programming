//Queue Collision
#include <stdio.h>
#define N 5
int s[N]; //storage space of N size

int main()
{
	int i,x,h,j;
	
	for(i=0; i<N; i++)
		s[i]=0; //all the storage are initialized as zero
		
	for(i=0; i<N; i++) //read N data to store
	{
		printf("data:");//assuming entered data is greater than 0
		scanf("%d",&x);
		
		h=x % N; //calculate hash, the index to store data at
		printf("hash:%d\n",h);
		if(s[h]==0) //if no collision then store
			s[h]=x;
		else //if collision then
		{
			printf("collision at %d\n",h); //print the collision index
			j=h;
			do //find the empty location from collision onwards
			{
				if(j==N-1) //if reached to the last location
					j=-1;  //start from first location
				if(s[++j]==0) //find the empty location
					{	s[j]=x; break; } //store 	
			}while(j!=h);
		}
	}
	
	printf("storage:\n"); //print storage content
	for(i=0; i<N; i++)
		printf("%d\n",s[i]);
}