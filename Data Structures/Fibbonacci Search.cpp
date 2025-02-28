#include<iostream>
using namespace std;
int fib_search(int arr[], int x, int n)
{
    int t1 = 0; 
    int t2 = 1; 
    int next = t1+t2; 

    while (next < n) 
    {
        t1 = t2;
        t2 = next;
        next = t1+t2;
    }
    int offset = -1;
    
    while (next > 1) 
{
	int i = min(offset + t2, n - 1);
    if (arr[i] < x) 
    {
        next=t2 ;
        t2 = t1;
        t1 = next - t2;
        offset = i;
    }
    else if (arr[i] > x) 
    {
        next = t1;
        t2 = t2 - t1;
        t1 = next- t2;
    }
    else
    return i;
}


    if (t2 && arr[offset + 1] == x)
        return offset + 1;
    return -1;
}
 
int main()
{
	int a[99],i,n,x;
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
	cout<<"enter element to search:";
	cin>>x;
    int ind =fib_search(a, x, n);
  if(ind>=0)
    cout<<x<<" is found at index: "<<ind;
  else
    cout<<x<<" isn't present in the array";
    return 0;                                                                                                                                                     
}