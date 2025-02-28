#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int data;
	struct node * next;
}Node;

Node* head1=NULL;
Node* head2=NULL;

Node* Create_LinkedList(Node* start)
{
	Node * new_node,*ptr;
	int val;
	printf("Enter -1 to End\n");
	printf("Enter the Data :");
	scanf("%d",&val);
	while(val!=-1)
	{
		new_node=(Node*)malloc(sizeof(Node));
		new_node->data=val;
		new_node->next=NULL;
		if(start==NULL)
		{
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next=new_node;
		}
		printf("Enter the Data :");
		scanf("%d",&val);
	}
return start;
}

Node* Display(Node* start)
{
	Node* ptr;
	ptr=start;
	printf("head=>  ");
	while(ptr!=NULL)
	{
		printf("%d  ",ptr->data);
		ptr=ptr->next;
	}
	printf("=>NULL\n");
return start;
}

Node* Merge(Node*start1, Node*start2)
{
	Node* ptr;
	ptr=start1;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=start2;
return start1;
}

Node* Sort(Node*start)
{
	Node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
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

Node* Reverse_List(Node *start)
{
	Node *preptr,*ptr,*postptr;
	preptr=NULL;
	ptr=start;
	postptr=start;
	while(postptr!=NULL)
	{
		postptr=postptr->next;
		ptr->next=preptr;
		preptr=ptr;
		ptr=postptr;
	}
	start=preptr;
return start;
}

int Search(int arr[100], int value,int size)
{
	int i;
	for(i=0;i<=size;i++)
	if(arr[i]==value)
	return 1;
return -1;	
}

Node* Remove_duplicates(Node* start)
{
	int arr[100],size=0;
	Node *prev,*cur;
	cur=start;
	prev=NULL;
	memset(arr,-1,100);
	while(cur!=NULL)
	{
		if(Search(arr,cur->data,size)==1)
		{
			prev->next=cur->next;
			free(cur);
		}
		else
		{
			arr[size]=cur->data;
			prev=cur;
			size++;
		}
		cur=prev->next;
	}
return start;	
}

int main()
{
	printf("CREATING 1ST LINKED LIST\n");
	head1=Create_LinkedList(head1);
	head1=Display(head1);
	printf("CREATING 2ND LINKED LIST\n");
	head2=Create_LinkedList(head2);
	head2=Display(head2);
	printf("MERGING LINKED LISTS\n");
	head1=Merge(head1,head2);
	head1=Display(head1);
	printf("SORTING LINKED LISTS\n");
	head1=Sort(head1);
	head1=Display(head1);
	printf("REMOVING DUPLICATES\n");
	head1=Remove_duplicates(head1);
	head1=Display(head1);
	printf("REVERSING LINKED LISTS\n");
	head1=Reverse_List(head1);
	head1=Display(head1);
return 0;
}