#include<stdio.h>
#include<stdlib.h>
static long long int count=0;
long long int fib(int n)
{
	count++;
	long long int sum ;
	if(n<=0)
	exit(1);
	if(n==1)
	return 0;
	if (n==2)
	return 1;
	sum=fib(n-1)+fib(n-2);
return sum;
}
int main()
{
	int n;
	printf("Enter the term :");
	scanf("%d",&n);
	printf("In fib series %d term is  : %lld\n",n,fib(n));
	printf("%lld times function is called",count);
return 0;	
}