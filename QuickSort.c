//quick sort
#include<stdio.h>
#define SIZE 5

int data[SIZE];

int part(int l, int h)
{
	int pivot = data[h];//last element is always pivot
	int i=l-1;
	int j;
	int temp;
	/*rearrange data from l to h in such way that 
	elements on left of pivot will be less than pivot (left list)
	elements on right of pivot will be greater than pivot (right list)
	pivot will be in between*/
	for(j=l; j<h; j++)//for each element in list till before the h (as h is pivot)
	{
		if(data[j] <= pivot)//if the current data is less than pivot
		{
			i++;//put it in the left list
			temp=data[i];
			data[i]=data[j];
			data[j]=temp;
		}
	}
	//make pivot in between the left list and right list
	temp=data[h];
	data[h]=data[i+1];
	data[i+1]=temp;
	
	return i+1;//return pivot position
	
}

void quick(int low, int high)
{
	int pi; //the pivot element position
	if(low < high)
	{
		pi = part(low, high);//create left list & right list
		quick(low, pi-1);//quick sort left list 
		quick(pi+1, high);//quick sort right list
	}
}

int main()
{
	int k;
	//read the data
	printf("Data before sort:\n");
	for(k=0; k<SIZE; k++)
		scanf("%d",&data[k]);
	//sort the data
	quick(0,SIZE-1);
	//print the sorted data
	printf("\nData after sort:\n");
	for(k=0; k<SIZE; k++)
		printf("%d\n",data[k]);
}