#include <iostream>
using namespace std;

typedef struct node
{ 
  int key;
  struct node *left, *right;
}Node;

Node* stack[10]; int top=-1;

Node* createnode(int key1)
{
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->key=key1;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void push(Node * node)
{
    stack[++top]=node;   
}

Node* pop()
{
   return stack[top--];
}

void inorder(Node* root)
{
    int flag=0;
    Node * cur;
    cur = root;
    cout<<"In order : ";
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
            cout<<cur->key<<" ";
            cur=cur->right;
        } 
        else
        {
        	flag=1;
        	printf("\n");
		}
    }
}
void pre(Node* root)
{
    int flag=0;
    Node * cur;
    cur = root;
    cout<<"Pre order : ";
     while(!flag)
    {
        if(cur!=NULL)
        {
           push(cur);
           cout<<cur->key<<" ";
           cur=cur->left;
        }
        else if(top!= -1)
        {
        	cur = pop();
            cur=cur->right;
        } 
        else
        {
        	flag=1;
        	printf("\n");
		}
    }
} 

void post(Node* root)
{
    int flag=0;
    Node * cur;
    cur = root;
    cout<<"Post order : ";
    do
    {
    	while(cur)
    	{
    		if(cur->right)
    		push(cur->right);
    		push(cur);
    		cur=cur->left;
		}
		cur = pop();
		if(cur->right && stack[top]==cur->right)
		{
			pop();
			push(cur);
			cur=cur->right;
		}
		else
		{
			printf("%d ",cur->key);
			cur=NULL;
		}
}while(top!= -1);
	
}
int main() 
{
    int a;
    cin>>a;
	Node* root=createnode(a);
    cin>>a;
    root->left=createnode(a);
    cin>>a;
    root->right=createnode(a);
   cin>>a;
    root->left->left=createnode(a);
   cin>>a;
   root->left->right=createnode(a);
   cin>>a;
    root->right->left=createnode(a);
   cin>>a;
   root->right->right=createnode(a);
  inorder(root);
  pre(root);
  post(root);
  return 0;
}