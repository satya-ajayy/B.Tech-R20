/#include<iostream>
using namespace std;
int main()
{
	int a[99],i,j,n;
	int tmp,small;
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
	//selection sort
	for(i=0;i<n-1;i++)
	{
		small=i;
		for(j=i+1;j<n;j++)
		if(a[j]<a[small])
		small=j;
		if(i!=small)
		{
		tmp=a[i];
		a[i]=a[small];
		a[small]=tmp;
		}
	}
	//printing an sorted arary
	cout<<"sorted array"<<endl;
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
return 0;
}