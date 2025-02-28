#include<stdio.h>
void towersofhanoi(int n, char from,char to, char aux)
{
	if (n==1)
	{
		printf("Move disk 1 from %c to % c\n",from,to);
		return;
	}
	towersofhanoi(n-1,from,aux,to);
	printf("Move disk %d from %c to % c\n",n,from,to);
	towersofhanoi(n-1,aux,to,from);
}

int main()
{
	int n = 5;
	towersofhanoi(n,'A','C','B');
return 0;
}