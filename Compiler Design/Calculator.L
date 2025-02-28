%{
#include<stdio.h>
int op = 0, i;
float a, b;
void digi();
%}

%%

[0-9]+|([0-9]*)"."([0-9]+) digi();
"+" op = 1;
"-" op = 2;
"*" op = 3;
"/" op = 4;
"^" op = 5;
";" exit(0);
\n  printf("The Answer : %f\nEnter expression : ", a);

%%

void digi() {
  if (op == 0) a = atof(yytext);
  else {
    b = atof(yytext);
    switch(op) {
      case 1: a = a + b; break;
      case 2: a = a - b; break;
      case 3: a = a * b; break;
      case 4: a = a / b; break;
      case 5: for (i = a; b > 1; b--) a = a * i; break;
    }
    op=0;
  }
}

void main(int argv,char *argc[]) {
  printf("\nEnter expression : ");
  yylex();
}

int yywrap() {
  return 1;
}