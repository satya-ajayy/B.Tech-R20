#include<stdio.h>
#include<conio.h>
#include<math.h>
int smallest(int a[99],int n)
{
	int i,min;
	min=0;
	for(i=0;i<n;i++)
	if(a[i]<=a[min])
	min=i;
	return min;
}
int linear_search(int a[99],int find,int n)
{
	int i,k=0;
	for(i=0;i<n;i++)
	if(find==a[i])
	k=i;
	return k;
}
void find_neraest(int a[99],int n)
{
	int i,sum=0,average;
	int b[99];
	int lock=-1,lock1=-1;
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	average=sum/n;
	lock=linear_search(a,average,n);
	if(lock!=0)
	printf("%d",average);
	else
	{
		for(i=0;i<n;i++)
		b[i]=abs(sum-(a[i]*n));
		for(i=0;i<n;i++)
		printf("%d  ",b[i]);
		lock1=smallest(b,n);
		printf("\n%d\n",lock1);
		printf("%d\n",a[lock1]);
	}		
}
int main()
{
	int a[99],i,n;
	int *ptr ;
	ptr=&a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	 	scanf("%d",ptr+i);
	}
find_neraest(a,n);
return 0;
}