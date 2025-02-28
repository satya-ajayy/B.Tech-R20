#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i=0,top=0;
char stack[20],ip[20];
void push(char c){
    if(top>=20)
    printf("stack overflow");
    else
    stack[top++]=c;
}
void pop(){
    if(top<0)
    printf("stack underflow");
    else 
    top--;
}
void error(){
    printf("\nsyntax error!!string is invalid");
    exit(0);
}
int main(){
    int n;
    printf("the given grammer is \n\nE->TE'\nE'->+TE'|epsilon\nT->FT'\nT'->*FT'|epsilon\nF->(E)|i\nENTER THE STRING TO BE PARSED:");
    scanf("%s",ip);
    n=strlen(ip);
    ip[n]='$';
    ip[n+1]='\0';
    push('$');
    push('E');
    puts(stack);
    while(ip[i]!='\0'){
         puts(stack);
        if(ip[i]=='$'&&stack[top-1]=='$'){
            printf("\nsuccessful parsing of the string");
            return 1;
        }
        else if(ip[i]==stack[top-1]){
            printf("\nmatch of %c",ip[i]);
            i++;
            pop();
        }
        else {
            if(stack[top-1]=='E'&&(ip[i]=='i'||ip[i]=='(')){
                printf("\nE->TE'");
                pop();
                push('A');
                push('T');
            }
            else if(stack[top-1]=='A'&&(ip[i]=='i'||ip[i]=='+')){
                printf("\nE->+TE'");
                pop();
                push('A');
                push('T');
                push('+');
            }
            else if(stack[top-1]=='A'&&(ip[i]==')'||ip[i]=='$')){
                printf("\nE'->epsilon");
                pop();
            }
            else if(stack[top-1]=='T'&&(ip[i]=='i'||ip[i]=='(')){
                printf("\nT'->FT'");
                pop();
                push('B');
                push('F');
            }
            else if(stack[top-1]=='B' && (ip[i]=='+'||ip[i]==')'||ip[i]=='$')){
                printf("\nT'->epsilon");
                pop();
            }
            else if(stack[top-1]=='T'&&(ip[i]=='+')){
                printf("\nT'->*FT'");
                pop();
                push('B');
                push('F');
                push('*');
            }
            else if(stack[top-1]=='F'&&ip[i]=='i'){
                printf("\nF->i");
                pop();
                push('i');
            }
             else if(stack[top-1]=='F'&&ip[i]=='('){
                printf("\nF->(E)");
                pop();
                push(')');
                push('E');
                push('(');
            }
            else
            error();
        }
    }
}