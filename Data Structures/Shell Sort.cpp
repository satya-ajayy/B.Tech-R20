#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a[99],i,j,n;
	int tmp,gap;
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
	//shell sort
	for(gap=n/2;gap>=1;gap=gap/2)
	{
		for(j=gap;j<n;j++)
		{
			for(i=j-gap;i>=0;i=i-gap)
			{
				if(a[i]>a[i+gap])
				{
				tmp=a[i];
				a[i]=a[i+gap];
				a[i+gap]=tmp;
				}
				else
				break;
			}
		}
	}
	//printing an sorted arary
	cout<<"sorted array"<<endl;
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
return 0;
}