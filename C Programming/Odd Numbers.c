#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	char ch, snum[99];
	int n, i;
	printf("Enter n:");
	scanf("%d", &n);
	
	fp=fopen("Output.txt","w");
	if(fp==NULL)
	{
		printf("File does not exist!!!\n Or Can't be Creatable");
		exit(1);
	}

	for(i=1;i<n;i++)
	if(i%2==1)
	{
		fprintf(fp,itoa(i,snum,10));
		fprintf(fp,"\n");
	}
		
	fclose(fp);

return 0;	
}
