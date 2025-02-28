#include<stdio.h>
#include<stdlib.h>
 long long int  fib(int n)
{
	if(n<=0)
	exit(1);
    long long int fibArray[n],i;
    fibArray[1]=0,fibArray[2] = 1;
    for(i=3;i<=n; i++)
    fibArray[i]=fibArray[i-1]+fibArray[i-2];
    return fibArray[n];
}

int main()
{
    int n;
    printf("Enter the term :");
	scanf("%d",&n);
    printf("In fib series %d term is  : %lld\n",n,fib(n));
    return 0;
}
   