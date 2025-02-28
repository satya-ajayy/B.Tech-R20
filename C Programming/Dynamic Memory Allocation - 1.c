#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int *iptr;
    char *cptr;
    float *fptr;
 
    iptr=(int*)malloc(1*sizeof(int));
    cptr=(char*)malloc(1*sizeof(char));
    fptr=(float*)malloc(1*sizeof(float));
     
    printf("Enter integer value: ");
    scanf("%d",iptr);
    printf("Enter character value: ");
    scanf("%c",cptr);
    printf("Enter float value: ");
    scanf("%f",fptr);
     
    printf("Inputted value are: %d, %c, %.2f\n",*iptr,*cptr,*fptr);
     
    free(iptr);
    free(cptr);
    free(fptr);
 
return 0;
}
