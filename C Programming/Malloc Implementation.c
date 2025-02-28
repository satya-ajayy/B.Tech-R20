#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i;
	printf("Enter the value of n:");
	scanf("%d",&n);
	
	int * A = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("enter the value :");
		scanf("%d",A+i);
	}
	
	for(i=0;i<n;i++)
	printf("%d  ",*(A+i));
}