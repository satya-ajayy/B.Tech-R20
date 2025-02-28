#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node*left;
	struct node*right;
}Node;
Node*start=NULL;

//creates Doubly linked list(clear)
Node* Create_DoubleLinkedList(Node *start)
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
			new_node->right=NULL;
			new_node->left=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->right!=NULL)
			ptr=ptr->right;
			ptr->right=new_node;
			new_node->left=ptr;
			new_node->right=NULL;
		}
		printf("Enter the data :");
		scanf("%d",&val);
	}
return start;	
}

//to dipslay list(clear)
Node* Display(Node *start)
{
	Node *ptr;
	if(start==NULL)
	printf("Double LinkedList Is Empty\n");
	else
	{
		ptr=start;
		printf("Double Linked List In Entered Order : \n");
		printf("Head==> ");
		while(ptr!=NULL)
		{
			printf("%d  ",ptr->data);
			ptr=ptr->right;
		}
	printf("==>Null\n");
	}
return start;
}

//to dipslay list in reverse(clear)
Node* Display_Reverse(Node *start)
{
	Node *ptr;
	if(start==NULL)
	printf("Double LinkedList Is Empty\n");
	else
	{
		ptr=start;
		while(ptr->right!=NULL)
		ptr=ptr->right;
		printf("Double Linked List In Reversed Order : \n");
		printf("<==Null ");
		while(ptr!=NULL)
		{
			printf("%d  ",ptr->data);
			ptr=ptr->left;
		}
	printf("<==Head\n");
	}
return start;
}

//To find the length  of Doubly linked list(clear)
int Find_length(Node *start)
{
	Node *ptr;
	int length=0;
	ptr=start;
	if(start==NULL)
	return 0;
	else
	{
		while(ptr!=NULL)
		{
			length++;
			ptr=ptr->right;
		}
	
	}	
return length;
}

//search a value(clear)
int Search_Val(Node *start,int val)
{
	Node *ptr;
	int flag=0;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->data==val)
		flag=1;
		ptr=ptr->right;
	}
	if(flag==1)
		return 1;
	else
		return 0;
}

//Insertion at beginning(clear)
Node* Insert_Beg(Node *start)
{
	Node *new_node;
	int val;
	printf("Enter the data :");
	scanf("%d",&val);
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=val;
	new_node->left=NULL;
	new_node->right=start;
	start->left=new_node;
	start=new_node;
return start;
}

//Insertion at before a node (clear)
Node* Insert_Before(Node *start)
{
	Node *ptr,*new_node;
	int val,num,key;
	printf("Enter the value before which data is to be inserted :");
	scanf("%d",&num);
	key= Search_Val(start,num);
	if(key)
	{
		new_node=(Node*)malloc(sizeof(Node));
		ptr=start;
		while(ptr->data!=num)
		ptr=ptr->right;
		if (ptr==start)
		{
			start=Insert_Beg(start);
		}
		else
		{
			printf("Enter the data :");
			scanf("%d",&val);
			new_node->right=ptr;
			new_node->data=val;
			new_node->left=ptr->left;
			ptr->left->right=new_node;
			ptr->left=new_node;
		}
	}
	else
	{
		printf("Value is not found to Operate\n");
	}
return start;
}

//Insertion at Ending(clear)
Node* Insert_End(Node *start)
{
	Node *ptr,*new_node;
	int val;
	printf("Enter the data :");
	scanf("%d",&val);
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=val;
	ptr=start;
	while(ptr->right!=NULL)
	ptr=ptr->right;
	ptr->right=new_node;
	new_node->left=ptr;
	new_node->right=NULL;
return start;
}

//insertion at specific position(clear)
Node* Insert_Specific(Node *start)
{
	Node *ptr,*preptr,*new_node;
	int val, pos,i;
	printf("Enter The Position Of The Node:");
	scanf("%d",&pos);
	if(pos==1)
	{
		start=Insert_Beg(start);
	}
	
	else if(Find_length(start)+1==pos)
	{
		start=Insert_End(start);
	}
	
	else if(Find_length(start)+1<pos)
	{
		printf("Position is out of Range\n");
	}
	
	else
	{
		printf("Enter the data :");
		scanf("%d",&val);
		new_node=(Node*)malloc(sizeof(Node));
		new_node->data=val;
		ptr=start;
		for(i=1;i<pos;i++)
		{
		preptr=ptr;
		ptr=ptr->right;
		}
		preptr->right=new_node;
		ptr->left=new_node;
		new_node->left=preptr;
		new_node->right=ptr;
	}
return start;
}

//Insertion at after a node(clear)
Node* Insert_After(Node *start)
{
	Node *ptr,*new_node;
	int val,num,key;
	printf("Enter the value after which data is to be inserted :");
	scanf("%d",&num);
	key= Search_Val(start,num);
	if(key)
	{
		new_node=(Node*)malloc(sizeof(Node));
		ptr=start;
		while(ptr->data!=num)
		ptr=ptr->right;
		if(ptr->right==NULL)
		{
			start=Insert_End(start);
		}
		else
		{
			printf("Enter the data :");
			scanf("%d",&val);
			new_node->left=ptr;
			new_node->right=ptr->right;
			ptr->right->left=new_node;
			ptr->right=new_node;
			new_node->data=val;
		}
	}
	else
	{
		printf("Value is not found to Operate\n");
	}
return start;
}

//Deletion at beginning(clear)
Node* Delete_Beg(Node* start)
{
	Node *ptr;
	ptr=start;
	start=start->right;
	start->left=NULL;
	free(ptr);
return start;
}

//Deletion at Ending(clear)
Node* Delete_End(Node* start)
{
	Node *ptr;
	ptr=start;
	while(ptr->right!=NULL)
	ptr=ptr->right;
	ptr->left->right=NULL;
	free(ptr);
return start;
}

//Delete at before a node(clear)
Node* Delete_Before(Node *start)
{
	Node *ptr,*preptr;
	int num,key;
	printf("Enter the value before which data is to be Deleted :");
	scanf("%d",&num);
	key= Search_Val(start,num);
	if(key)
	{
		ptr=start;
		while(ptr->data!=num)
		{
			preptr=ptr;
			ptr=ptr->right;
		}
		if (ptr==start)
		{
			printf("There is No Value Before That Node\n");
		}
		else if(ptr->left==start)
		{
			start=Delete_Beg(start);
		}
		else 
		{
			ptr->left=preptr->left;
			preptr->left->right=ptr;
		}
		free(preptr);
	}
	else
	{
		printf("Value is not found to Operate\n");
	}
return start;
}

//delete at specific position(clear)
Node* Delete_Specific(Node *start)
{
	Node *ptr,*preptr;
	int pos,i;
	ptr=start;
	printf("Enter The Position Of The Node:");
	scanf("%d",&pos);
	if(pos==1)
	{
		start=Delete_Beg(start);	
	}
	
	else if(Find_length(start)==pos)
	{
		start=Delete_End(start);
	}
	
	else if(Find_length(start)<pos)
	{
		printf("Position is out of Range\n");
	}
	
	else
	{
		for(i=1;i<pos;i++)
		{
			preptr=ptr;
			ptr=ptr->right;
		}
		preptr->right=ptr->right;
		ptr->right->left=preptr;
		free(ptr);
	}
return start;
}

//Delete after a node(not clear)
Node* Delete_After(Node *start)
{
	Node *ptr,*postptr;
	int num,key;
	printf("Enter the value after which data is to be Deleted :");
	scanf("%d",&num);
	key= Search_Val(start,num);
	if(key)
	{
		ptr=start;
		postptr=start->right;
		while(ptr->data!=num)
		{
			ptr=ptr->right;
			postptr=ptr->right;
		}
		if(ptr->right==NULL)
		{
			printf("There is No Value After That Node\n");
		}
		else
		{
			postptr->right->left=ptr;
			ptr->right=postptr->right;
			free(postptr);
		}
	}
	else
	{
		printf("Value is not found to Operate\n");
	}
return start;
}

//to update given value in any node(clear)
Node* Update_Val(Node *start,int pos,int val)
{
	Node *ptr;
	int i;
	ptr=start;
	if(Find_length(start)<pos)
	{
		printf("Position is out of Range\n");
	}
	else
	{
		for(i=1;i<pos;i++)
		ptr=ptr->right;
		ptr->data=val;
	}
return start;
}

//sort the linked list in ascending order(clear)
Node* Ascending_Order(Node*start)
{
	Node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->right!=NULL)
	{
		ptr2=ptr1->right;
		while(ptr2!=NULL)
		{
			if(ptr1->data > ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->right;
		}
	ptr1=ptr1->right;
	}
return start;		
}

//sort the linked list in dscending order(clear)
Node* Dscending_Order(Node*start)
{
	Node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->right!=NULL)
	{
		ptr2=ptr1->right;
		while(ptr2!=NULL)
		{
			if(ptr1->data < ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->right;
		}
	ptr1=ptr1->right;
	}
return start;		
}

//to find sum(clear)
Node* Sumof_List(Node *start)
{
	Node *ptr;
	int sum=0;
	ptr=start;
	while(ptr!=NULL)
	{
		sum=sum+ptr->data;
		ptr=ptr->right;
	}
	printf("Sum of elements in linked list is : %d\n",sum);
return start;
}

//to find product(clear)
Node* Productof_List(Node *start)
{
	Node *ptr;
	int mul=1;
	ptr=start;
	while(ptr!=NULL)
	{
		mul=mul*ptr->data;
		ptr=ptr->right;
	}
	printf("Product of elements in linked list is : %d\n",mul);
return start;
}

//to get max node(clear)
int Max_Node(Node *start)
{
	int max;
	Node *ptr;
	if(start==NULL)
	printf("Double LinkedList Is Empty\n");
	else
	{
		ptr=start;
		max=ptr->data;
		while(ptr!=NULL)
		{
			if(ptr->data > max)
			{
				max=ptr->data;
			}
			ptr=ptr->right;
		}
	}
return max;
}

//to get min node(clear)
int Min_Node(Node *start)
{
	int min;
	Node *ptr;
	if(start==NULL)
	printf("Double LinkedList Is Empty\n");
	else
	{
		ptr=start;
		min=ptr->data;
		while(ptr!=NULL)
		{
			if(ptr->data < min)
			{
				min=ptr->data;
			}
		ptr=ptr->right;
		}
	
	}
return min;
}

//to find position of node(clear)
int Find_Pos(Node *start,int val)
{
	Node *ptr;
	int key,i=0;
	if(start==NULL)
	{
		printf("Double LinkedList Is Empty\n");
	}
	else
	{
		key= Search_Val(start,val);
		if(key)
		{ 	ptr=start;
			for(i=0;ptr->data!=val;i++)
			ptr=ptr->right;	
			return i+1;	
		}
		else
		return -1;
	}
}

// to swap max and min nodes(clear)
Node* Swap_MaxMin(Node* start)
{
	int max,min,maxpos,minpos;
	if(start==NULL)
	{
		printf("Double LinkedList Is Empty\n");
	}
	else
	{
		max=Max_Node(start);
		min=Min_Node(start);
		maxpos=Find_Pos(start,max);
		minpos=Find_Pos(start,min);
		start = Update_Val(start,maxpos,min);
		start = Update_Val(start,minpos,max);
	}
return start;
}

//to delete the complete list items(clear)
Node* Delete_List(Node *start)
{
	Node *ptr;
	ptr=start;
	while(ptr->right!=NULL)
	start=Delete_End(start);
	free(start);
	start=NULL;
return start;
}

int main()
{
	int option,val1,key,num,min;
	int max,index,val2,val3,pos;
	printf("--------------MAIN MENU---------------\n");
	printf("1. To Create DoublyLinkedList\n");
	printf("2. To Display DoublyLinkedList\n");
	printf("3. To Display DoublyLinkedList In Reverse\n");
	printf("4. To Insert Node At Beggining\n");
	printf("5. To Insert Node Before a Value\n");
	printf("6. To Insert Node At Specific Position\n");
	printf("7. To Insert Node After a Value\n");
	printf("8. To Insert Node At Ending\n");
	printf("9. To Delete Node At Beggining\n");
	printf("10.To Delete Node Before a Value\n");
	printf("11.To Delete Node At Specific Position\n");
	printf("12.To Delete Node After a Value\n");
	printf("13.To Delete Node At Ending\n");
	printf("14.To Update A Value in Node\n");
	printf("15.To Search A Value in DoublyLinkedList\n");
	printf("16.To Sort in Ascending Order\n");
	printf("17.To Sort in Dscending Order\n");
	printf("18.To Find Length of DoublyLinkedList\n");
	printf("19.To Find Sum Of Nodes in DoublyLinkedList\n");
	printf("20.To Find Product Of Nodes in DoublyLinkedList\n");
	printf("21.To Find Max Node of DoublyLinkedList\n");
	printf("22.To Find Min Node of DoublyLinkedList\n");
	printf("23.To Find Position Of a Node\n");
	printf("24.To Swap Max Node and Min Node\n");
	printf("25.To Delete Complete DoublyLinkedList\n");
	printf("26.To Exit From Program\n");
	while (1)
	{
		printf("\nEnter your Option : ");
		scanf("%d",&option);
		if(option==26)
		{
		printf("you exited from code bye!");
		break;	
		}
		else
		{
		switch(option)
		{
			case 1:
				start=Create_DoubleLinkedList(start);
				break;
			case 2:
				start=Display(start);
				break;
			case 3:
				start=Display_Reverse(start);
				break;
			case 4:
				start=Insert_Beg(start);
				break;
			case 5:
				start=Insert_Before(start);
				break;
			case 6:
				start=Insert_Specific(start);
				break;
			case 7:
				start=Insert_After(start);
				break;
			case 8:
				start=Insert_End(start);
				break;
			case 9:
				start=Delete_Beg(start);
				break;
			case 10:
				start=Delete_Before(start);
				break;
			case 11:
				start=Delete_Specific(start);
				break;
			case 12:
				start=Delete_After(start);
				break;
			case 13:
				start=Delete_End(start);
				break;	
			case 14:
				printf("Enter The Position Of The Node:");
				scanf("%d",&pos);
				printf("Enter the data To Update :");
				scanf("%d",&val3);
				start=Update_Val(start,pos,val3);
				break;
			case 15:
				printf("Enter the data To Search :");
				scanf("%d",&num);
				key=Search_Val(start,num);
				if(key==1)
				printf("Value is found in linked list\n");
				else
				printf("Value is  not found in linked list\n");
				break;
			case 16:
				start=Ascending_Order(start);
				break;	
			case 17:
				start=Dscending_Order(start);
				break;
			case 18:
				val1=Find_length(start);
				if(val1==0)
				printf("Doubly LinkedList Is Empty\n");
				else
				printf("Length Of List Is : %d\n",val1);
				break;	
			case 19:
				start=Sumof_List(start);
				break;	
			case 20:
				start=Productof_List(start);
				break;
			case 21:
				max=Max_Node(start);
				printf("Largest value in List is %d \n",max);
				break;
			case 22:
				min=Min_Node(start);
				printf("Smallest value in List is %d \n",min);
				break;
			case 23:
				printf("Enter the data To Get Position :");
				scanf("%d",&val2);
				index=Find_Pos(start,val2);
				if(index==-1)
				printf("Value is not found in List\n");
				else
				printf("Value is found at position %d\n",index);
				break;
			case 24:
				start=Swap_MaxMin(start);
				break;	
			case 25:
				start=Delete_List(start);
				break;	
			default:
				printf("wrong choice choose from(1 to 25)\n");
		}
		}	
	}
return 0;
}