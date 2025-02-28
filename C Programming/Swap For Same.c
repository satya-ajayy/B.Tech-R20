#include<stdio.h>
#include<string.h>

int check_code(char a[99],char b[99]){
	int i;
	for(i=0;i<strlen(a);i++){
		if(a[i]!=b[i]){
			return 0;
			break;
		}
		else
		return 1;
	}
}

int swap(char a[99],char b[99],int i, int j){
	int tmp,cout=0;
	tmp=a[i];a[i]=b[j];b[j]=tmp;
	cout=check_code(a,b);
	if(cout==1)
	return cout;
	else{
		tmp=a[i];a[i]=b[j];b[j]=tmp;	
	}
}

int main(){
	char a[99],b[99];
	int i,j,tmp,cout=0;
	
	printf("enter string1:"); scanf("%s",a);
	printf("enter string2:"); scanf("%s",b);
	
	for(i=0;i<strlen(a);i++){
		for(j=0;j<strlen(b);j++){
			cout=swap(a,b,i,j);
		}
	}
	if (cout==1) printf("YES");
	else printf("NO");
return 0;
}