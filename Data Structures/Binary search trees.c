#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}Node;

struct node *root=NULL;

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
    if (root == NULL)
	return -1;
    if (root->data == val)
    return 1;
    if (val < root->data)
   	Search_Node(root->left,val);
	else
    Search_Node(root->right,val);
}

Node* Find_Smallest(Node* root)
{
	if(root==NULL||root->left==NULL)
	return root;
	else
	return Find_Smallest(root->left);
}

Node* Find_Largest(Node* root)
{
	if(root==NULL||root->right==NULL)
	return root;
	else
	return Find_Largest(root->right);
}

void In_Order(Node* root)
{
	if (root != NULL) 
	{
		In_Order(root->left);
		printf("%d  ", root->data);
		In_Order(root->right);
	}
}

void Pre_Order(Node* root)
{
	if (root != NULL) 
	{
		printf("%d  ", root->data);
		Pre_Order(root->left);
		Pre_Order(root->right);
	}
}

void Post_Order(Node* root)
{
	if (root != NULL) 
	{
		Post_Order(root->left);
		Post_Order(root->right);
		printf("%d  ", root->data);
	}
}

Node* Delete_Node(Node* root, int val)
{
	if (root==NULL)
	return root;
	if (val < root->data)
	root->left=Delete_Node(root->left,val);
	else if (val > root->data)
	root->right=Delete_Node(root->right,val);
	else 
	{
		if (root->left==NULL) 
		{
			Node* temp=root->right;
			free(root);
			return temp;
		}
		else if (root->right ==NULL) 
		{
			Node* temp=root->left;
			free(root);
			return temp;
		}
		Node* temp=Find_Smallest(root->right);
		root->data=temp->data;
		root->right=Delete_Node(root->right,temp->data);
	}
return root;
}

int Total_Nodes(Node* root)
{
	if(root==NULL)
	return 0;
	else 
	return (Total_Nodes(root->left)+Total_Nodes(root->right)+1);
}

int Leaf_Nodes(Node* root)
{
	if(root==NULL)
	return 0;
	else if(root->left==NULL && root->right==NULL)
	return 1;
	else 
	return (Leaf_Nodes(root->left)+Leaf_Nodes(root->right));
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
    printf("5. To Delete a Node\n");
    printf("6. To Get Pre order\n");
	printf("7. To Get In order\n");
	printf("8. To Get Post order\n");
	printf("9. To Get Total Nodes\n");
	printf("10.To Get Leaf Nodes \n");
    printf("11.To Exit\n");
    
    while(1)
    {
    	printf("\nenter your choice :");
        scanf("%d",&choice);
        if(choice==11)
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
        	printf("Enter the data to delete :");
			scanf("%d",&val2);
          	root= Delete_Node(root,val2);
            break;
            case 6:
            printf("Pre Order  : ");
          	Pre_Order(root);
            break;
            case 7:
            printf("In Order   : ");
          	In_Order(root);
            break;
            case 8:
            printf("Post Order : ");
          	Post_Order(root);
            break;
            case 9:
            printf("Total Nodes : %d\n",Total_Nodes(root));
            break;
            case 10:
            printf("Total leaves : %d\n",Leaf_Nodes(root));
            break;
        	default: 
		  	printf("Enter a number from 1 to 11\n");
        	break;
       }
    	}
	}
return 0;
}