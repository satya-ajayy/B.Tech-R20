#include<stdio.h>
#include<math.h>

int arr[100]={-1,};

int insert(int arr[100],int size,int value)
{
	int parent,checker,temp,i;
	size++;
	arr[size]=value;
	checker=size;
	while(checker>1)
	{
		parent=floor(checker/2);
		if(arr[parent]<arr[checker])
		{
			temp=arr[parent];
			arr[parent]=arr[checker];
			arr[checker]=temp;
		}
			checker=parent;
	}
	for(i=1;i<=size;i++)
	printf("%d  ",arr[i]);
	printf("\n");
}

int main()
{
	int size = 0,n,val,i;
	printf("Enter how many do you want to insert:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter data to insert:");
		scanf("%d",&val);
		insert(arr,size,val);
		size++;
	}
return 0;	
}