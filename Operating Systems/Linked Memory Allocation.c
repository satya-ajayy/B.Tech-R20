#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int f[50]={0},p,i,st,len,j,c,k,a;
	printf("Enter how many blocks already allocated: ");
	scanf("%d",&p);
	printf("Enter blocks already allocated: ");
	for(i=0;i<p;i++)
	{
		scanf("%d",&a);
		f[a]=1;
		printf("%d->%d\t",a,f[a]);
	}
	x: printf("\nEnter index starting block and length: ");
	scanf("%d %d", &st,&len);
	k=len;
	if(f[st]==0)
	{
		for(j=st;j<(st+k);j++)
		{
			if(f[j]==0)
			{
				f[j]=1;
				printf("%d-->",j);
			}
			else
			{
				k++;
			}
		}
		printf("NULL\n");
	}
	else
	printf("%d starting block is already allocated \n",st);
	printf("Do you want to enter more file(Yes - 1/No - 0)");
	scanf("%d", &c);
	if(c==1)
	goto x;
	else
	exit(0);
}