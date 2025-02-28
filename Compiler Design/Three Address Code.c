#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char res[100];

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
char* postfix(char s[])
{
	int j=0;
	int top=-1;
	int len = strlen(s);
	char stack[100];
	for(int i = 0;i<len;i++)
	{
		if(isalnum(s[i]))
			res[j++]=s[i];
		else if(s[i]=='(')
			stack[++top] = s[i];
		else if(s[i]==')')
		{
			while (top > -1 && stack[top] != '(')
                res[j++] = stack[top--];
            top--;
		}
		else
		{
			while (top > -1 && prec(stack[top]) >= prec(s[i]))
                res[j++] = stack[top--];
            stack[++top] = s[i];
		}
	}
	while (top > -1)
        res[j++] = stack[top--];
    res[j] = '\0';
}
void three_add_code(char A[])
{
	char B[1000],e,a,b;
	int i,tp=-1;
	for(i=0;A[i]!='\0';i++)
	{
		e=A[i];
		if(e<123&&e>96)
		{
			B[++tp]=e;
			continue;
		}
		b=B[tp--];
		a=B[tp--];
		printf("t = %c %c %c\n",a,e,b);
		B[++tp]='t'; 
	}
}
int main()
{
	char A[1000];
	printf("\nExpression : ");
	scanf("%[^\n]s", A);
	postfix(A);
	printf("postfix : %s\n\n", res);
	three_add_code(res);
	return 0;
}