#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	fp = fopen("Output.txt","w");
	fprintf(fp,"Hii banagram!\n");
	if(fp==NULL)
    {
        printf("File does not created!!!");
        exit(1);
    }
    printf("Written successfully.");
	fclose(fp);
	
return 0;
}