#include<stdio.h>
int main()
{
 
    FILE *fp;  
    char fName[20];
 
    printf("\nEnter file name to create :");
    scanf("%s",fName);
 
    fp=fopen(fName,"w");
    if(fp==NULL)
    {
        printf("File does not created!!!");
        exit(0);
    }
 
    printf("File created successfully.");

    putc('A',fp);
    putc('B',fp);
    putc('C',fp);
    printf("\nData written successfully.\n");
    fclose(fp);
 
    fp=fopen(fName,"r");
    if(fp==NULL)
    {
        printf("\nCan't open file!!!");
        exit(0);
    }
 
    printf("Contents of file is :\n");
    printf("%c\n",getc(fp));
    printf("%c\n",getc(fp));
    printf("%c",getc(fp));
 
    fclose(fp);
    return 0;
}
