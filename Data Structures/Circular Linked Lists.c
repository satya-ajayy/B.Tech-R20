#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node*next;
}Node;
Node*start=NULL;

//creates circular linked list
Node* Create_CircularLinkedList(Node *start)
{
	Node* ptr,*new_node;
	int val;
	printf("Enter -1 to end\n");
	printf("Enter the data :");
	scanf("%d",&val);
	while(val!=-1)
	{
		new_node=(Node*)malloc(sizeof(Node));
		new_node->data=val;
		if(start==NULL)
		{
			new_node->next=new_node;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=start;
		}
		printf("Enter the data :");
		scanf("%d",&val);
	}
return start;	
}

//to dipslay list
Node* Display(Node *start)
{
	Node *ptr;
	if(start==NULL)
	printf("Circular LinkedList Is Empty\n");
	else
	{
		ptr=start;
		printf("Circular Linked List ---> ");
		while(ptr->next!=start)
		{
			printf("%d  ",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n",ptr->data);
	}
return start;
}

//Insertion at beginning
Node* Insert_Beg(Node *start)
{
	Node *ptr,*new_node;
	int val;
	printf("Enter the data :");
	scanf("%d",&val);
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=val;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;
return start;
}

//insertion at specific position
Node* Insert_Specific(Node *start)
{
	Node *ptr,*preptr,*new_node;
	int val, pos,i;
	printf("Enter The Position Of The Node:");
	scanf("%d",&pos);
	printf("Enter the data :");
	scanf("%d",&val);
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=val;
	ptr=start;
	for(i=1;i<pos;i++)
	{
	preptr=ptr;
	ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
return start;
}


//insertion at ending
Node* Insert_End(Node *start)
{
	Node *ptr,*new_node;
	int val;
	printf("Enter the data :");
	scanf("%d",&val);
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=val;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=start;
return start;
}

//deletion in beginning
Node* Delete_Beg(Node *start)
{
	Node *ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=start->next;
	free(start);
	start=ptr->next;
return start;
}

//delete at specific position
Node* Delete_Specific(Node *start)
{
	Node *ptr,*preptr;
	int pos,i;
	ptr=start;
	printf("Enter The Position Of The Node:");
	scanf("%d",&pos);
	if(pos==1)
	start=Delete_Beg(start);
	else
	{
		for(i=1;i<pos;i++)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
	}
return start;
}

//delete node at ending 
Node* Delete_End(Node *start)
{
	Node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
return start;
}

//to update given value in any node
Node* Update_Val(Node *start)
{
	Node *ptr;
	int pos,i,val;
	ptr=start;
	printf("Enter The Position Of The Node:");
	scanf("%d",&pos);
	printf("Enter the data To Update :");
	scanf("%d",&val);
	for(i=1;i<pos;i++)
	ptr=ptr->next;
	ptr->data=val;
return start;
}

//search a value
Node* Search_Val(Node *start)
{
	Node *ptr;
	int val,flag=0;
	ptr=start;
	printf("Enter the data To Search :");
	scanf("%d",&val);
	while(ptr->next!=start)
	{
		if(ptr->data==val)
		flag=1;
		ptr=ptr->next;
	}
	if(flag==1)
	printf("Value is found in linked list\n");	
	else
	printf("Value is  not found in linked list\n")	;
return start;
}

//sort the linked list
Node* Sort(Node*start)
{
	Node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=start)
	{
		ptr2=ptr1->next;
		while(ptr2!=start)
		{
			if(ptr1->data > ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->next;
		}
	ptr1=ptr1->next;
	}
return start;		
}

// to reverse the linked list
Node* Reverse_List(Node *start)
{
	Node *end,*preptr,*ptr,*pstptr;
	end=start;
	while(end->next!=start)
	end=end->next;
	ptr=start;
	pstptr=ptr->next;
	if(start=NULL)
	printf("Circular LinkedList Is Empty\n");
	else
	{
		while(ptr!=end)
		{
			preptr=ptr;
			ptr=pstptr;
			pstptr=ptr->next;
			ptr->next=preptr;
		}
		pstptr->next=end;
		end=pstptr;
	}
return end->next;	
}

//To find the length  linked list
Node* Find_length(Node *start)
{
	Node *ptr;
	int length=1;
	ptr=start;
	if(start==NULL)
	printf("Circular LinkedList Is Empty\n");
	else
	{
		while(ptr->next!=start)
		{
			length++;
			ptr=ptr->next;
		}
	printf("Length Of List Is : %d\n",length);
	}	
return start;
}

//to find sum
Node* Sumof_List(Node *start)
{
	Node *ptr;
	int sum=0;
	ptr=start;
	while(ptr->next!=start)
	{
		sum=sum+ptr->data;
		ptr=ptr->next;
	}
	sum=sum+ptr->data;
	printf("Sum of elements in linked list is : %d\n",sum);
return start;
}

//to find product
Node* Productof_List(Node *start)
{
	Node *ptr;
	int mul=1;
	ptr=start;
	while(ptr->next!=start)
	{
		mul=mul*ptr->data;
		ptr=ptr->next;
	}
	mul=mul*ptr->data;
	printf("Product of elements in linked list is : %d\n",mul);
return start;
}

//to delete the complete list ithems
Node* Delete_List(Node *start)
{
	Node *ptr;
	ptr=start;
	while(ptr->next!=start)
	start=Delete_End(start);
	free(start);
	start=NULL;
return start;
}

int main()
{
	int option;
	printf("----------MAIN MENU-----------\n");
	printf("1. To Create Circular LinkedList\n");
	printf("2. To Display linked list\n");
	printf("3. To Insert Node At Beggining\n");
	printf("4. To Insert Node At Specific Position\n");
	printf("5. To Insert Node At Ending\n");
	printf("6. To Delete Node At Beggining\n");
	printf("7. To Delete Node At Specific Position\n");
	printf("8. To Delete Node At Ending\n");
	printf("9. To Update A Value in Node\n");
	printf("10.To Search A Value in Node\n");
	printf("11.To Sort The Circular LinkedList\n");
	printf("12.To Reverse The Circular LinkedList\n");
	printf("13.To Find Length of Circular LinkedList\n");
	printf("14.To Find Sum Of Nodes in Circular LinkedList\n");
	printf("15.To Find Product Of Nodes in Circular LinkedList\n");
	printf("16.To Delete Circular LinkedList\n");
	printf("17.EXIT\n");
	while (1)
	{
		printf("Enter your Option : ");
		scanf("%d",&option);
		if(option==17)
		{
		printf("you exited from code bye!");
		break;	
		}
		else
		{
		switch(option)
		{
			case 1:
				start=Create_CircularLinkedList(start);
				break;
			case 2:
				start=Display(start);
				break;
			case 3:
				start=Insert_Beg(start);
				break;
			case 4:
				start=Insert_Specific(start);
				break;	
			case 5:
				start=Insert_End(start);
				break;
			case 6:
				start=Delete_Beg(start);
				break;
			case 7:
				start=Delete_Specific(start);
				break;
			case 8:
				start=Delete_End(start);
				break;
			case 9:
				start=Update_Val(start);
				break;
			case 10:
				start=Search_Val(start);
				break;
			case 11:
				start=Sort(start);
				break;
			case 12:
				start=Reverse_List(start);
				break;	
			case 13:
				start=Find_length(start);
				break;
			case 14:
				start=Sumof_List(start);
				break;
			case 15:
				start=Productof_List(start);
				break;
			case 16:
				start=Delete_List(start);
				break;
			default:
				printf("wrong choice\n");
		}
		}	
	}
return 0;
}