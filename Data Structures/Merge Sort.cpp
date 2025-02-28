#include<iostream>
using namespace std;
void merge(int a[99], int lb,int mid,int ub)
{
	int i,j,k;
	int b[99];
	i=lb;j=mid+1;k=lb;
	while(i<=mid&&j<=ub)
	{
		if(a[i]<=a[j])
		{
		b[k]=a[i];
		i++;k++;
		}
		else
		{
		b[k]=a[j];
		j++;k++;
		}
	}
	if(i>mid)
	{
		while(j<=ub)
		{
		b[k]=a[j];
		j++;k++;
		}
	}
	else
	{
		while(i<=mid)
		{
		b[k]=a[i];
		i++;k++;
		}
	}
	for(i=0;i<=ub;i++)
	a[i]=b[i];
}
void merge_sort(int a[99],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{	mid=(lb+ub)/2;
		merge_sort(a,lb,mid);
		merge_sort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}
int main()
{
	int a[99],i,j,n;
	int tmp,flag;
	cout<<"enter n:";
	cin>>n;
	//taking an array
	for(i=0;i<n;i++)
	{
		cout<<"enter a["<<i<<"]:";
		cin>>a[i];
	}
	//printing an arary
	cout<<"entered array"<<endl;
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	merge_sort(a,0,n-1);
	//printing an sorted arary
	cout<<"sorted array"<<endl;
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
return 0;
}