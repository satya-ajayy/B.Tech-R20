#include<iostream>
#include<iomanip>
#include<string>
#define N 50
using namespace std;
char stack[N];
int top=-1;
int empty()
{
	if(top==-1)
	return 0;
	else
	return 1;
}
void push(char land)
{
	top++;
	stack[top]=land;
}
char pop()
{
	top--;
	return stack[top];
}
int main()
{
	char str[99],land;
	int i,check1,check2,flag=1;
	cout<<"enter a string:";
	cin>>str;
for(i=0;i<strlen(str);i++)
{
	if(str[i]=='(' || str[i]=='[' || str[i]=='{')
	{
		push(str[i]);
	}
	if(str[i]==')' || str[i]==']' || str[i]=='}')
	{
		check1=empty();
		if(check1==0)
		flag=0;
		else
		{
		land=pop();
		if ( str[i]==')'&& (land=='['|| land=='{') ) 
		flag=0;
		if ( str[i]==']'&& (land=='('|| land=='{') ) 
		flag=0;
		if ( str[i]=='}'&& (land=='['|| land=='(') ) 
		flag=0;
		}
	}
}
check2=empty();
if(check2==0)
flag=0;
if(flag==1)
cout<<"Valid Expression";
else
cout<<"In Valid Expression";
return 0;
}