#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
  int data;
  struct node *left,*right;
  int ht;
};
struct node *insert(struct node *,int);
struct node *delete(struct node *,int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
int height(struct node *);
struct node *rotate_right(struct node *);
struct node *rotate_left(struct node *);
struct node *RR(struct node *);
struct node *LL(struct node *);
struct node *RL(struct node *);
struct node *LR(struct node *);
int balance_fac(struct node *);
struct node *root=NULL;
int main()
{
    
    int x,n,i=0,ch;
    printf("---AVL TREE OPERATIONS---");
    printf("\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Quit\n\n");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter number of elements:");
                   scanf("%d",&n);
                   for(i=0;i<n;i++)
                   {
                       scanf("%d",&x);
                       root=insert(root,x);
                   }
            break;
            case 2:printf("Enter the data:");
                   scanf("%d",&x);
                   root=insert(root,x);
            break;
            case 3:printf("Enter the data:");
                   scanf("%d",&x);
                   root=delete(root,x);
            break;
            case 4:printf("Preorder: ");
                   preorder(root);
                   printf("\nInorder: ");
                   inorder(root);
                   printf("\nPostorder: ");
                   postorder(root);
            break;
            case 5:exit(1);
            default:printf("Enter Valid choice!!");
            printf("%d ",height(root));
        }
    }while(ch!=5);
    return 0;
}
struct node *insert(struct node *temp,int x)
{
    if(temp==NULL)
    {
        temp=(struct node *)malloc(sizeof(struct node));
         temp->data=x;
         temp->left=NULL;
         temp->right=NULL;
    }
    else
        if(x>temp->data)
        {
            temp->right=insert(temp->right,x);
            if(balance_fac(temp)==-2)
            if(x>temp->right->data)
                temp=RR(temp);
        	else
            	temp=RL(temp);
    }
    else if(x<temp->data)
    {
        temp->left=insert(temp->left,x);
        if(balance_fac(temp)==2)
        if(x<temp->left->data)
            temp=LL(temp);
        else
            temp=LR(temp);
    }
    temp->ht=height(temp);
    return(temp);
}
struct node *delete(struct node *temp,int x)
{
    struct node *ptr;
    if(temp==NULL)
    {
        return NULL;
    }
    else if(x>temp->data)
    {
        temp->right=delete(temp->right,x);
        if(balance_fac(temp)==2)
        if(balance_fac(temp->left)>=0)
            temp=LL(temp);
        else
            temp=LR(temp);
    }
    else if(x<temp->data)
    {
        temp->left=delete(temp->left,x);
        if(balance_fac(temp)==-2)
        if(balance_fac(temp->right)<=0)
            temp==RR(temp);
        else
            temp=RL(temp);
    }
    else
    {
        if(temp->right!=NULL)
        {
            ptr=temp->right;
            while(ptr->left!=NULL)
                ptr=ptr->left;
            temp->data=ptr->data;
            temp->right=delete(temp->right,ptr->data);
            if(balance_fac(temp)==2)
            if(balance_fac(temp->left)>=0)
                temp=LL(temp);
            else
                temp=LR(temp);
        }
        else
            return(temp->left);
    }
    temp->ht=height(temp);
    return(temp);
}
int height(struct node *temp)
{
    int lh,rh;
    if(temp==NULL)
        return 0;
    if(temp->left==NULL)
        lh=0;
    else
        lh=1+temp->left->ht;
    if(temp->right==NULL)
        rh=0;
    else
        rh=1+temp->right->ht;
    if(lh>rh)
        return lh;
    return rh;
}
struct node *rotate_right(struct node *x)
{
    struct node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return y;
}
struct node *rotate_left(struct node *x)
{
    struct node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
    return y;
}
struct node *RR(struct node *temp)
{
    temp=rotate_left(temp);
    return(temp);
}
struct node *LL(struct node *temp)
{
    temp=rotate_right(temp);
    return(temp);
}
struct node *LR(struct node *temp)
{
    temp->left=rotate_left(temp->left);
    temp=rotate_right(temp);
    return(temp);
}
struct node *RL(struct node *temp)
{
    temp->right=rotate_right(temp->right);
    temp=rotate_left(temp);
    return(temp);
}
int balance_fac(struct node *temp)
{
    int lh,rh;
    if(temp==NULL)
        return 0;
    if(temp->left==NULL)
        lh=0;
    else
        lh=1+temp->left->ht;
    if(temp->right==NULL)
        rh=0;
    else
        rh=1+temp->right->ht;
    return(lh-rh);
}
void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d(%d)\t",temp->data,balance_fac(temp));
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d(%d)\t",temp->data,balance_fac(temp));
        inorder(temp->right);
    }
}
void postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d(%d)\t",temp->data,balance_fac(temp));
    }
}