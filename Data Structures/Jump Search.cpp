#include<iostream>
#include<cmath>
using namespace std;
int jump_search(int a[99],int n,int data)
{
	int l,r,mid,step,i,j;
	l=0,r=n-1;
	step=sqrt(n);
	for(i=0;i<n;i=i+step)
	{
		if(data<a[i]){
		r=i;
		break;}
		else
		l=i;
	}
	for(j=l;j<=r;j++)
	if(a[j]==data)
	return j;
	return -1;
}
int main()
{
	int i,n,a[99],choice,index;
	cout<<"enter n:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter a["<<i<<"]:";
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
 cout<<"enter choice:";
 cin>>choice;
 index=jump_search(a,n,choice);
 if (index==-1)
 cout<<"element not found";
 else
 cout<<"element found at index "<<index;
 return 0;
}