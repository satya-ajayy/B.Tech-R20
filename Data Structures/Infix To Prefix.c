#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define N 50
char stack[N];
int top=-1;

void push(char land)
{
	top++;
	stack[top]=land;
}

char pop()
{
	char land;
	land=stack[top];
	top--;
	return land;
}

int get_priority(char op)
{
	if(op=='^')
	return 2;
	else if(op=='/'|| op=='*' || op=='%')
	return 1;
	else if(op=='+'|| op=='-')
	return 0;
}

void infix_postfix(char infix[99],char postfix[99])
{
	int i=0,j=0;
	char tmp;
	while(infix[i]!='\0')
{
	if(infix[i]=='(')
	{
	push(infix[i]);
	i++;
	}
	else if(infix[i]==')')
	{
		while(top!=-1 && stack[top]!='(')
		{
			postfix[j]=pop();
			j++;
		}
		if(top==-1)
		{
			printf("invalid expression");
			exit(1);
		}
		tmp=pop();
		i++;
	}
	else if(isdigit(infix[i]) || isalpha(infix[i]))
	{
		postfix[j]=infix[i];
		j++;i++;
	}
	else if (infix[i]=='+' || infix[i]=='-' ||infix[i]=='*' ||
		infix[i]=='%' || infix[i]=='/' )
	{
		while((top!=-1) && (stack[top]!='(') && (get_priority(stack[top])
		>=get_priority(infix[i])))
		{
			postfix[j]=pop();
			j++;
		}
		push(infix[i]);
		i++;
	}
	
	else if (infix[i]=='^')
	{
		push(infix[i]);
		i++;
	}
	
	else
	{
		printf("in valid expression");
		exit(1);
	}
}
	while((top!=-1) && (stack[top]!='('))
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';	
}

int main()
{
	char infix[99],postfix[99];
	printf("only use () these brackets\n");
	printf("enter any infix expression:\n");
	gets(infix);
	infix_postfix(infix,postfix);
	printf("Coresponding postfix expression is:\n");
	puts(postfix);
}