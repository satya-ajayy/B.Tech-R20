#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next;
}Node;
Node *start=NULL;
Node* create_linkedlist(Node *start)
{
	Node *new_node,*ptr;
	int num;
	printf("Enter -1 to end");
	printf("\nEnter the data:");
	scanf("%d",&num);
	while (num!=-1)
	{
		new_node=(Node*)malloc(sizeof(Node));
		new_node->data=num;
		if(start==NULL)
		{
		new_node->next=NULL;
		start=new_node;
		}
		else
		{
		ptr=start;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=new_node;
		new_node->next=NULL;
		}
		printf("Enter the data:");
		scanf("%d",&num);
	}
return start;
}
Node* dispaly(Node*start)
{
	Node *ptr;
	ptr=start;
	while (ptr!=NULL)
	{
		printf("%d  ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
Node* insert_beg(Node*start)
{
	Node *new_node;
	int num;
	printf("Enter the data:");
	scanf("%d",&num);
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
return start;	
}
Node* insert_end(Node *start)
{
	Node *new_node, *ptr;
	int num;
	printf("Enter the data:");
	scanf("%d",&num);
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=num;
	new_node->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=new_node;
return start;
}
Node* insert_before(Node*start)
{
	Node *new_node, *ptr, *preptr;
	int num,val;
	printf("Enter the data:");
	scanf("%d",&num);
	printf("Enter the value before which data has to be inserted:");
	scanf("%d",&val);
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
	preptr=ptr;
	ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
return start;
}
Node* insert_after(Node*start)
{
	Node *new_node, *ptr, *preptr;
	int num,val;
	printf("Enter the data:");
	scanf("%d",&num);
	printf("Enter the value after which data has to be inserted:");
	scanf("%d",&val);
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=num;
	ptr=start;
	preptr=ptr;
	while(ptr->data!=val)
	{
	preptr=ptr;
	ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
return start;
}
Node* delete_beg(Node *start)
{
	Node *ptr;
	if(start==NULL)
	printf("Linked List is Empty");
	else
	{
	ptr=start;
	start=start->next;
	free(ptr);
	}
return start;
}
Node* delete_end(Node *start)
{
	Node *ptr;
	ptr=start;
	while(ptr->next->next!=NULL)
	ptr=ptr->next;
	ptr->next=NULL;
	free(ptr->next->next);
return start;
}
Node* delete_node(Node *start)
{
	Node *ptr,*preptr;
	int val;
	printf("Enter the value of node which has to be deleted:");
	scanf("%d",&val);
	ptr=start;
	if(ptr->data==val)
	{
		start=delete_beg(start);
		return start;
	}
	else
	{
		while(ptr->data!=val)
		{
		preptr=ptr;
		ptr=ptr->next;
		}
	}
	preptr->next=ptr->next;
	free(ptr);
return start;
}

int main()
{
	int option;
	printf("----------MAIN MENU-----------\n");
	printf("1. To Create LinkedList\n");
	printf("2. To Display The List\n");
	printf("3. To Add Node At Beginning\n");
	printf("4. To Add Node At Ending\n");
	printf("5. To Add Node Before A Give Node\n");
	printf("6. To Add Node After A Give Node\n");
	printf("7. To Delete a Node From The Beginning \n");
	printf("8. To Delete a Node From The Ending\n");
	printf("9. To Delete a Node\n");
	printf("10.EXIT\n");
	while (1)
	{
		printf("Enter your Option :");
		scanf("%d",&option);
		if(option==10)
		{
		printf("you exited from code bye!");
		break;
		}
		else
		{
		switch(option)
		{
			case 1:
				start=create_linkedlist(start);
				break;
			case 2:
				start=dispaly(start);
				break;
			case 3:
				start=insert_beg(start);
				break;
			case 4:
				start=insert_end(start);
				break;
			case 5:
				start=insert_before(start);
				break;
			case 6:
				start=insert_after(start);
				break;
			case 7:
				start=delete_beg(start);
				break;
			case 8:
				start=delete_end(start);
				break;
			case 9:
				start=delete_node(start);
				break;		
			default:
				printf("wrong choice");
		}
		}	
	}
return 0;
}