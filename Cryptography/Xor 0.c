#include<stdio.h>

int main(){
	int i;
	char * str = "HelloWorld";
	for(i=0;*(str+i)!='\0';i++){
		printf("%c",*(str+i) ^ 0);
	}
return 0;
}
