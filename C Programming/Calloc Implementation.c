#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i;
	printf("Enter the value of n:");
	scanf("%d",&n);
	int * A = (int *)calloc(n,sizeof(int));
	
	for(i=0;i<n;i++)
	printf("%4d  ",*(A+i));
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("enter the value of A[%d] : ",i+1);
		scanf("%d",A+i);
	}
	
	for(i=0;i<n;i++)
	printf("%4d ",*(A+i));
}