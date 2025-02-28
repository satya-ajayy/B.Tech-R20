#include<stdio.h>
#define MAX 500

int main(){
	int choice = 1;
	int page[MAX],i,n,f,off,pno;
	printf("enter No.of pages in memory : ");
	scanf("%d", &n);
	printf("Enter Page Size : ");
	scanf("%d", &f);
	for(i=0;i<MAX;i++)
		page[i] = -1;
	for(i=0;i<n;i++){
		printf("Enter the page table");
		printf("(-1 if page is not in any frame)\n");
		for(i=0;i<n;i++){
			printf("%d\t",i);
			scanf("%d", &page[i]);
		}
	}
		do{
			printf("\nEnter The logical adress :");
			scanf("%d %d", &pno,&off);
			if(page[pno]== -1){
				printf("The requested page is not available in any frame\n");
				printf("Do you Want to continue 1/0 : ");
				scanf("%d",&choice);
			}
			else{
				printf("Physical adress(i.e framno & offset) -->  %d %d",page[pno],off);
				printf("\nDo you Want to continue 1/0 : ");
				scanf("%d",&choice);
			}
	}while(choice == 1);
return 0;
}