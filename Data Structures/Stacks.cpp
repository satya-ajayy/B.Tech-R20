#include<iostream>
#include<iomanip>

#define N 50
using namespace std;
int stack[N];
int top=-1;

void push()
{
	int land;
	cout<<"Enter a number to be pushed into stack : ";
	cin>>land;
	if(top==N-1)
	{
	cout<<"Stack Over Flow "<<endl;
	}
	else
	{
	top++;
	stack[top]=land;
	cout<<land<<" is pushed into stack"<<endl;
	}
}
void pop()
{
	int land;
	if(top==-1)
	{
	cout<<"Stack Under Flow"<<endl;
	}
	else
	{
	land=stack[top];
	top--;
	cout<<land<<" is popped out from stack"<<endl;
	}
}
void peek()
{
	if(top==-1)
	{
	cout<<"Stack Is Empty"<<endl;
	}
	else
	{
	cout<<"The Top Element Of Stack Is :"<<stack[top]<<endl;
	}
}
void show_stack()
{
	int i;
	if(top==-1)
	{
	cout<<"Stack Is Empty"<<endl;
	}
	else
	{
	for(i=top;i>=0;i--)
	cout<<"stack["<<i<<"]:"<<stack[i]<<endl;
	}	
}
int main()
{
	int option;
	cout<<"----------MAIN MENU-----------"<<endl;
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Peek"<<endl;
	cout<<"4. Show_stack"<<endl;
	cout<<"5. EXIT"<<endl;
	while (true)
	{
		cout<<"Enter your Option : ";
		cin>>option;
		if(option==5)
		{
		cout<<"you exited from code bye!";
		break;	
		}
		else
		{
		switch(option)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				show_stack();
				break;
			default:
				cout<<"wrong choice"<<endl;
		}
		}	
	}
return 0;
}