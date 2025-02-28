#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[30];
int top=-1;

void push(char c)
{
	top++;
	stack[top]=c;
}

char pop()
{
	char c;
	if(top!=-1)
	{	
		c=stack[top];
		top--;
		return c;
	}
	return 'x';
}

void printstat()
{
	int i;
	printf("\n$");
	for(i=0;i<=top;i++)
		printf("%c",stack[i]);
}

void main()
{
	int i,j,k,l;
	char s1[20],ch1,ch2;
	printf("----LR PARSING----\n");
	printf("ENTER THE EXPRESSION:");
	scanf("%s",s1);
	l=strlen(s1);
	j=0;
	printf("$");
	for(i=0;i<l;i++)
	{
		if(s1[i]=='i' && s1[i+1]=='d')
		{
			s1[i]=' ';
			s1[i+1]='E';
			printstat();
			printf("id");
			push('E');
			printstat();
		}
		else if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/' ||s1[i]=='d')
		{
			push(s1[i]);
			printstat();
		}
    }
	printstat();
	while(1)
	{	
		ch1=pop();
		if(ch1=='x')
		{
			printf("\n$");
			break;
		}
		if(ch1=='+'||ch1=='/'||ch1=='*'||ch1=='-')
		{
			ch2=pop();
			if(ch2!='E')
			{
				printf("\nerrror");
				return ;
			}
			else
			{
				push('E');
				printstat();
			}
		}
	}
}