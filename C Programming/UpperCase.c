#include <stdio.h>
#include <ctype.h>
 
int main()
{
 
    const char *fileName="File.txt";
    const char *file="Output.txt";
    FILE *fp,*fp1;
    char ch;
     
    fp=fopen(fileName,"r");
    if(fp==NULL)
	{
        printf("Error in opening file.\n");
        return -1;
    }
    
    fp1=fopen(file,"w");
    if(fp1==NULL)
	{
        printf("Error in creating file.\n");
        return -1;
    }   
    
    while((ch=fgetc(fp))!=EOF)
	{
        if(islower(ch))
		{
            ch=ch-32;
        }
        putc(ch,fp1);                   
    }
    fclose(fp);
    fclose(fp1);
     
    fp=fopen(file,"r");
    if(fp==NULL)
	{
        printf("Error in opening file.\n");
        return -1;
    }
    printf("Content of file\n");
    while((ch=getc(fp))!=EOF)
	{
        printf("%c",ch);
    }
    printf("\n");
    fclose(fp);
    return 0;
}
