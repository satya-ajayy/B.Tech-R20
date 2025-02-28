#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;  
    char ch;
     
    fp=fopen("Output.txt","r");
    
    if(fp==NULL)
	{
        printf("Error in opening file.\n");
        exit(1);
    }
    
    printf("Content of file:\n");
    while((ch=getc(fp))!=EOF)
    printf("%c",ch);
    fclose(fp);
    
return 0;
}
