//Write C programs to simulate the File Allocation methods
//a)Contiguous 

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int f[50]={0},i,j,start,len,ch,flag;
	X:
	printf("Enter the starting block & length of file: ");
	scanf("%d%d",&start,&len);
	flag=0;
	for(j=start;j<(start+len);j++)
	{
		if(f[j]==1)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		for(j=start;j<(start+len);j++)
		{
		 	f[j]=1;
			printf("%d->%d\t",j,f[j]);
		}
	printf("\nThe File is allocated to disk");
	}
	else
	{
		printf("Block already allocated");	
	}
	
	printf("\nDo u want to enter more files?(y:1/n:0)");
	scanf("%d",&ch);
	if(ch==1)
		goto X;
	else
		exit(1);
}