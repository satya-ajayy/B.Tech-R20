#include <stdio.h>
#include <string.h>
#define is_even_parity 1

int binaryTodecimal(char num[])  
{  
    int i,decimal,mul=0;
    for(decimal=0,i=strlen(num)-1;i>=0;--i,++mul)  
    {  
        decimal = decimal + (num[i] - 48) * (1 << mul);  
    } 
return decimal;  
 }  

char Helper(char lst[])
{
	int count=0,i;
	for(i=0;i<=strlen(lst);i++)
		if(lst[i] == '1')
			count++;
    if(count%2 != 0)
    {
    	if(is_even_parity)
            return '1';
        else
            return '0';
	}
    else
	{
    	if(is_even_parity)
            return '0';
        else
            return '1';
	}       
}
	

void GetHammingCode(char d[])
{--
	char p1,p2,p4,p8;
	char arr1[10] = {d[0],d[2],d[3],d[5],d[6]};
	p1 = Helper(arr1);
	char arr2[10] = {d[0],d[1],d[3],d[4],d[6]};
    p2 = Helper(arr2);
    char arr3[10] = {d[3],d[4],d[5]};
    p4 = Helper(arr3);
    char arr4[10] = {d[0],d[1],d[2]};
    p8 = Helper(arr4);
    char Hcode[20] = {d[0],d[1],d[2],p8,d[3],d[4],d[5],p4,d[6],p2,p1};
    printf("Hamming Code For %s is %s\n",d,Hcode);
}

void IsCorrect(char l[11])
{
	char p1,p2,p4,p8;
	int error,i;
	char arr1[10] = {l[0],l[2],l[4],l[6],l[8],l[10]};
	p1 = Helper(arr1);
	char arr2[10] = {l[0],l[1],l[4],l[5],l[8],l[9]};
    p2 = Helper(arr2);
    char arr3[10] = {l[4],l[5],l[6],l[7]};
    p4 = Helper(arr3);
    char arr4[10] = {l[0],l[1],l[2],l[3]};
    p8 = Helper(arr4);
    char arr5[10] = {p8,p4,p2,p1};
    error = binaryTodecimal(arr5);
    if(error == 0)
        printf("Entered Hamming Code is Correct");
    else
    {
        if(l[11-error] == '1')
			l[11-error] = '0';
		else
			l[11-error] = '1';
        printf("Entered Hamming Code is Wrong\n");
        printf("Corrected Hamming Code is ");
        for(i=0;i<11;i++)
        	printf("%c",l[i]);
    }
}
        

int main()
{
	char data[10];
	printf("Enter Data :");
	scanf("%s",&data);
	GetHammingCode(data);
	char arr[11] = "10101101110";
	IsCorrect(arr);
}