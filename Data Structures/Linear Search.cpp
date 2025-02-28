#include<iostream>
using namespace std;
int main()
{
int a[99];
int i,choice,n;
cout<<"enter n:";
cin>>n;
for(i=0;i<n;i++)
{
	cout<<"enter a["<<i<<"]:";
	cin>>a[i];
}
for(i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<"\n";
cout<<"enter choice:";
cin>>choice;
for(i=0;i<n;i++)
{
	if(choice==a[i])
	cout<<"element found at index"<<i<<endl;
}
}