#include <stdio.h>
#include <stdlib.h>
 
typedef struct student
{
    char name[30];
   	char sex[7];
    float perc;
} Student;
 
int main()
{
    Student *st;
    int n,i;
     
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    st=(Student*)malloc(n*sizeof(Student));
     
    if(st==NULL)
    {
        printf("Insufficient Memory, Exiting... \n");
        return 0;
    }
     
    for(i=0; i<n; i++)
    {
        printf("\nEnter details of student  with Roll.No %3d :\n",i+1);
        printf("Enter Name: ");
        scanf(" ");
        gets((st+i)->name);
        printf("Enter Gender: ");
        scanf(" ");
        gets((st+i)->sex);
        printf("Enter Percentage: ");
        scanf("%f",&(st+i)->perc);
    }
     
    printf("\nEntered details are: roll.no\t    name     \tsex\t\tperc\n");
    for(i=0; i<n; i++)
    printf("%25d \t %10s \t %7s \t %.2f\n",(i+1),(st+i)->name,(st+i)->sex,(st+i)->perc);

return 0;
}
