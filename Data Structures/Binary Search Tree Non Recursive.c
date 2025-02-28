#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left, *right;
}Node;

Node* stack[10]; int top=-1;
struct node *root=NULL;

void push(Node * node)
{
    stack[++top]=node;   
}

Node* pop()
{
   return stack[top--];
}

Node * Insert_Node(Node* root)
{
	int val;
	Node *ptr1, *ptr2, *ptr3;
	printf("Enter -1 to end\n");
	printf("Enter the data :");
	scanf("%d",&val);
	
	while(val!=-1)
	{
		ptr1 = (Node *)malloc(sizeof(Node));
		ptr1->data=val;
		ptr1->left=NULL;
		ptr1->right=NULL;
		if(root==NULL)
		{
			root = ptr1;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{
			ptr2=NULL;
			ptr3=root;
			while(ptr3!=NULL)
			{
				ptr2=ptr3;
				if(val < ptr3->data)
				ptr3=ptr3->left;
				else
				ptr3=ptr3->right;
			}
			if(val<ptr2->data)
			ptr2->left=ptr1;
			else
			ptr2->right=ptr1;
		}
	printf("Enter the data :");
	scanf("%d",&val);	
	}
return root;
}

int Search_Node(Node* root,int val)
{
    Node*ptr=root;
    while(ptr)
    {
    	if(ptr->data == val)
    	return 1;
    	else if(ptr->data<val)
    	ptr=ptr->right;
    	else
    	ptr=ptr->left;
	}
	return -1;
}

Node* Find_Smallest(Node* root)
{
	Node * ptr = root;
	while(ptr->left!=NULL)
	ptr=ptr->left;
	return ptr;
}

Node* Find_Largest(Node* root)
{
	Node * ptr = root;
	while(ptr->right!=NULL)
	ptr=ptr->right;
	return ptr;
}
void InOrder(Node* root)
{
    int flag=0;
    Node * cur;
    cur = root;
    printf("In order : ");
     while(!flag)
    {
        if(cur!=NULL)
        {
           push(cur);
           cur=cur->left;
        }
        else if(top!= -1)
        {
        	cur = pop();
            printf("%d ",cur->data);
            cur=cur->right;
        } 
        else
        {
        	flag=1;
        	printf("\n");
		}
    }
}
int main()
{
    int choice,val1,val2,ans=-1;
    Node * ptr;
    printf("---------MAIN MENU---------\n");
    printf("1. To Build a Binary Search Tree\n");
    printf("2. To Search a Value\n");
    printf("3. To Find minimum element\n");
    printf("4. To Find maximum element\n");
    printf("5. To Print The Inorder Traversal\n");
    printf("6.To Exit\n");
    
    while(1)
    {
    	printf("\nenter your choice :");
        scanf("%d",&choice);
        if(choice==6)
        {
        	printf("You exited from the code Byeeee\n");	
        	break;
		}
    	else
    	{
    	switch(choice)
       	{
        	case 1:
          	root = Insert_Node(root);
            break;
        	case 2:
        	printf("Enter the data to search :");
			scanf("%d",&val1);
          	ans=Search_Node(root,val1);
          	if (ans==1)
          	printf("Data is present in tree\n");
          	else
          	printf("Data is not present tree\n");
            break;
        	case 3:
          	ptr=Find_Smallest(root);
          	printf("Smallest element is %d\n",ptr->data);
            break;
        	case 4:
          	ptr=Find_Largest(root);
          	printf("Largest element is %d\n",ptr->data);
            break;
        	case 5:
        	InOrder(root);
            break;
        	default: 
		  	printf("Enter a number from 1 to 11\n");
        	break;
       }
    	}
	}
return 0;
}