#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int *arr;
    int n,i;
    int sum=0;
     
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
     
    if(arr==NULL)
    {
        printf("Insufficient Memory, Exiting... \n");
        return 0;
    }
     
    printf("Enter %d elements:\n",n);
    for(i=0; i<n; i++)
    {
        printf("Enter element %3d: ",i+1);
        scanf("%d",(arr+i));
        sum=sum + *(arr+i);
    }
     
    printf("Array elements are:");
    for(i=0; i<n; i++)
    printf("%3d ",*(arr+i));
    printf("\nSum of all elements: %d\n",sum);
return 0;    
}
