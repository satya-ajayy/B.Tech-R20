//Write a C program to simulate the File allocation method 
//c)Indexed
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int f[50]={0}, index[50],i, n, st, len, j, c, k, ind,count=0;
	x:printf("Enter the index block: ");
	scanf("%d",&ind);
	if(f[ind]!=1)
	{
	 	printf("Enter no.of blocks needed for the index %d on the disk:\n",ind);
 		scanf("%d",&n);
	}
	else
	{
 		printf("%d index is already allocated \n",ind);
 		goto x;
	}
	y:
	count=0;
	printf("Enter Indices of file blocks for the index %d on the disk:\n",ind);
	for(i=0;i<n;i++)
	{
	 	scanf("%d", &index[i]);
 		if(f[index[i]]==0)
	 		count++;
	}
	if(count==n)
	{
	 	for(j=0;j<n;j++)
 			f[index[j]]=1;
 		printf("Allocated...File Indexed\n");
 		for(k=0;k<n;k++)
 			printf("%2d --> %2d : %d\n",ind,index[k],f[index[k]]);
	}
	else
	{
		printf("File block in the index is already allocated \n");
		printf("Enter other indices of file blocks\n");
		goto y;
	}
	printf("Do you want to enter more files(Yes - 1/No - 0)");	
	scanf("%d",&c);
	if(c==1)
		goto x;
	else
	 	exit(0);
	return 0;
}