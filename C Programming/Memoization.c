#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int memo[50];
static long long int count=0;
long long int fib(int n)
{
    count++;
	long long int sum ;
	long long int first,second;
	if(n<=0)
	exit(1);
	if(n==1)
	return 0;
	if (n==2)
	return 1;

    if (memo[n-1]!=-1)
    first=memo[n-1];
    else
    first=fib(n-1);
 
    if (memo[n-2]!=-1)
    second=memo[n-2];
    else
    second=fib(n-2);

    // memoization
    sum=first+second;
    memo[n]=sum;
return memo[n];
}
 
int main()
{
	memset(memo,-1,sizeof(memo));
	int n;
	printf("Enter the term :");
	scanf("%d",&n);
	printf("In fib series %d term is  : %lld\n",n,fib(n));
	printf("%lld times function is called",count);
return 0;	
}   