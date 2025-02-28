#include <stdio.h>

void printCheckSum(int* b1,int* b2,int n)
{
	int temp[n],carry=0,i,t;
	for(i=n-1;i>=0;i--)
	{
		t=b1[i]+b2[i]+carry;
		temp[i]=t%2;
		carry=t/2;
	}
	if(carry)
	{
		for(i=n-1;i>=0;i--)
		{
			t=temp[i]+carry;
			temp[i]=t%2;
			carry=t/2;
		}
	}
	
	//print ans
	printf("1's Sum : ");
	for(i=0;i<n;i++)
	printf("%d",temp[i]);
	printf("\n");
	printf("Checksum: ");
	for(i=0;i<n;i++)
	printf("%d",!temp[i]);
}

int main()
{
	int i,n;
	char dup_bits1[100],dup_bits2[100];
	int bits1[100],bits2[100];
	printf("Enter length of bits:");
	scanf("%d",&n);
	
	printf("Enter Subnet 1:");
	scanf("%s",&dup_bits1);
	
	for(i=0;i<n;i++)
		bits1[i]=dup_bits1[i]-'0';
	
	printf("Enter Subnet 2:");
	scanf("%s",&dup_bits2);
	
	for(i=0;i<n;i++)
		bits2[i]=dup_bits2[i]-'0';
	
	printf("Subnet 1: %s\n",dup_bits1);
	printf("Subnet 2: %s\n",dup_bits2);
	printCheckSum(bits1,bits2,n);
return 0;
}