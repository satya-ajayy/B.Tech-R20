#include<iostream>
using namespace std;
int main()
{
	int a[99],i,j,n;
	int tmp;
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
	//insertion sort
	for(i=1;i<n;i++)
	{
	tmp=a[i];
	j=i-1;
	while(j>=0 && a[j]>tmp)
	{
		a[j+1]=a[j];
		j--;
	}
	a[j+1]=tmp;
	}
	//printing an sorted arary
	cout<<"sorted array"<<endl;
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
return 0;
}