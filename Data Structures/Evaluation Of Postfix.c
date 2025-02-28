#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define N 50

int stack[N];
int top=-1;
void push(float land)
{
	if(top==N-1)
	{
	printf("Stack Over Flow\n");
	}
	else
	{
	top++;
	stack[top]=land;
	}
}
float pop()
{
	float land;
	if(top==-1)
	{
	printf("Stack Under Flow\n");
	}
	else
	{
	land=stack[top];
	top--;
	}
return land;
}
float evaluate(char postfix[99])
{
	int i=0,flag=0;
	float a,b,c;
	while(postfix[i]!='\0')
	{
		if(isdigit(postfix[i]))
		push((float)(postfix[i]-'0'));
		else if(postfix[i]==' ')
		flag++;
		else
		{
		b=pop();
		a=pop();
		switch(postfix[i])
			{
			case '+':
			c=a+b;
			break;
			case '-':
			c=a-b;
			break;
			case '*':
			c=a*b;
			break;
			case '%':
			c=(int)a%(int)b;
			break;
			case '/':
			c=a/b;
			break;
			case '^':
			c=pow(a,b);
			break;	
			case '$':
			c=pow(a,b);
			break;
			default:
			printf("invalid operator");
			break;	
			}
		push(c);
		}
	i++;		
	}
return (pop());
}
int main()
{
	float output;
	char str[99];
	printf("enter any postfix expression:");
	gets(str);
	output=evaluate(str);
	printf(" value of %s is: %f",str,output);
	return 0;
}
