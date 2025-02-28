#include<stdio.h>
int main()
{
 
    FILE *fp;  
    char fName[20];
 
    printf("Enter file name to create :");
    scanf("%s",fName);
    fp=fopen(fName,"w");
    if(fp==NULL)
    {
        printf("File does not created!!!");
        exit(1);
    }
 
    printf("File created successfully.");
    return 0;
}
