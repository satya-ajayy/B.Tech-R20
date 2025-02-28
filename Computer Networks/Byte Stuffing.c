#include<stdio.h>
#include<string.h>
int main()
{
    char byts[500],sd,ed;
    printf("Enter characters to be stuffed: ");
    scanf("%s", &byts);getchar();
    printf("Enter Starting Delimiter: ");
    scanf("%c", &sd);getchar();
    printf("Enter Ending Delimiter: ");
    scanf("%c", &ed);
    printf("%c ",sd);
    for(int i=0;i<strlen(byts);i++){
    	if(byts[i]==sd || byts[i]==ed)
    		printf("%c%c",byts[i],byts[i]);
    	else
    		printf("%c",byts[i]);
	}
	printf(" %c",ed);
return 0;
}