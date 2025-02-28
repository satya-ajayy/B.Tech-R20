#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m=100,s[50],n=1,j,k,ch,ef=0;
    printf("1) Insert a segment\n2) Delete a segment\n3) exit\n");
    printf("enter your choice :");
    scanf("%d",&ch);
    while(1)
    {
    switch(ch)
    {
        case 1:printf("enter size of segment :");
               scanf("%d",&s[n]);
               if(s[n] < m)
               {
                   m=m-s[n];
                   n++;
                   printf("available memory :%d\n",m);
                }
                else
                {
                    ef=m;
                    printf("external fragmentation is :%d\n",ef);
                }
            break;
        case 2:printf("enter segment number for deletion :");
                scanf("%d",&j);
                m=m+s[j];
                if(j!=n-1)
                	ef=ef+s[j];
            	printf("external fragmentation:%d\n",ef);
                s[j]=0;
                printf("available memory:%d\n",m);
                break;
        case 3:exit(1);
        default:printf("enter valid choice (0-3)");
     }
    printf("enter choice :");
    scanf("%d",&ch);
    }
    return 0;
}