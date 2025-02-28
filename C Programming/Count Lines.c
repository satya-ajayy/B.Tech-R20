#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	char ch;
	int Count=0;
	
	fp=fopen("Output.txt","r");
	if(fp==NULL)
	{
		printf("File does not exist!!!\n Or Can't be Creatable'");
		exit(1);
	}

	while((ch=fgetc(fp))!=EOF)
	if(ch=='\n')
	Count++;
	fclose(fp);
	printf("Total number of lines are: %d\n",Count);
return 0;	
}
