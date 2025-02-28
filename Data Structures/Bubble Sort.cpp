#include<iostream>
using namespace std;
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
	//bubble sort
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				flag++;
			}
		}
		if(flag==0)
		break;
	}
	//printing an sorted arary
	cout<<"sorted array"<<endl;
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
return 0;
}