#include<iostream>
#include<cmath>
using namespace std;
int interpolatian_search(int a[99],int n,int data)
{
	int l,r,mid;
	l=0,r=n-1;
	while(l<r)
	{
		mid=l+(r-l)*(data-a[l])/(a[r]-a[l]);
		if(data==a[mid])
		{
			return mid;
			break;
		}
		else if(data<a[mid])
		r=mid-1;
		else
		l=mid+1;
	}
}
int main()
{
	int i,n,a[99],choice,index=-1;
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
 index=interpolatian_search(a,n,choice);
 if (index==-1)
 cout<<"element not found";
 else
 cout<<"element found at index "<<index;
 return 0;
}