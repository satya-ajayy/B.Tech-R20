#include<stdio.h>
#include<conio.h>

int main()
{
	int a[10][10],b[10][10],c[10][10];
	int i,j,rows,cols;
	
	printf("Enter no of rows :");
	scanf("%d",&rows);
	printf("Enter no of cols :");
	scanf("%d",&cols);
	
	for(i=0;i<rows;i++){
	for(j=0;j<cols;j++){
	printf("Enter a[%d][%d] : ",i,j);
	scanf("%d",&a[i][j]);}}
	
	for(i=0;i<rows;i++){
	for(j=0;j<cols;j++){
	if(j>=i)
	b[i][j]=a[i][j];
	else
	b[i][j]=0;}}
	
	for(i=0;i<rows;i++){
	for(j=0;j<cols;j++){
	printf("%4d",b[i][j]);}
	printf("\n");}
	
return 0;
}