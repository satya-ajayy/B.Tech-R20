#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct stack
{
	int data;
	struct stack *next;
}Stack;

Stack*top=NULL;

Stack* push(stack*top)
{
	stack *ptr;int val;
	printf("Enter a value to be pushed into stack : ");
	scanf("%d",&val);
	ptr=(Stack*)malloc(sizeof(Stack));
	ptr->data=val;
	if(top==NULL)
	{
	ptr->next=NULL;
	top=ptr;
	}
	else
	{
	ptr->next=top;
	top=ptr;
	}
return top;
}

Stack* Show_stack(Stack*top)
{
	Stack *ptr;
	ptr=top;
	if(top==NULL)
	printf("Stack is Empty\n");
	else
	{
		int i;
		for(i=1;ptr!=NULL;i++)
		{
		printf("stack[%d]: %d\n",i,ptr->data);
		ptr=ptr->next;
		}
	}
return top;
}

Stack* pop(Stack*top)
{
	Stack *ptr;
	ptr=top;
	if(top==NULL)
	printf("Stack Underflow\n");
	else
	{
	top=top->next;
	printf("The value %d is deleted from stack\n",ptr->data);
	free(ptr);
	}
return top;
}

void peek(Stack* top)
{
	if(top==NULL)
	printf("Stack is empty\n");
	else
	printf("Top value of stack at present is: %d\n",top->data);
}

int main()
{
	int option;
	printf("----------MAIN MENU-----------\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Show_stack\n");
	printf("5. EXIT\n");
	while (1)
	{
		printf("Enter your Option : ");
		scanf("%d",&option);
		if(option==5)
		{
		printf("you exited from code bye!");
		break;	
		}
		else
		{
		switch(option)
		{
			case 1:
				top=push(top);
				break;
			case 2:
				top=pop(top);
				break;
			case 3:
				peek(top);
				break;
			case 4:
				top=Show_stack(top);
				break;
			default:
				printf("wrong choice\n");
		}
		}	
	}
return 0;
}