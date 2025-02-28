#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int iden_c=0,oper_c=0,keyw_c=0,int_c=0,flt_c=0,hfile_c=0;

bool isValidDelimiter(char ch) {
   if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';'
    || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' 
	|| ch == '{' || ch == '}' || ch == '\n' || ch == '"')
   		return (true);
   return (false);
}

bool isValidOperator(char ch){
   if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '='){
   		oper_c++;
		return (true);
   }
   		
   return (false);
}


bool isvalidIdentifier(char* str){
	int i = 0;
	if (!isalpha(str[i]) && !str[i] != '_') return false;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_')
            return false;
    }
    iden_c++;
    return true;
}

const char keywords[32][15] = {
    "if", "else", "while", "do", "break", "continue", "int", "double", "float", "return", 
    "char", "case", "sizeof", "long", "short", "typedef", "switch", "unsigned", "void", "static",
    "struct", "goto", "union", "enum", "auto", "extern", "volatile", "const", "signed", "for",
    "register", "default"
};

bool isValidKeyword(char* str) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keywords[i]) == 0){
        	keyw_c++;
        	return true;
		}
             
    }
    return false;
}

const char directives[5][10] = {"#include","#define","#ifdef","#undef","#pragma"};


bool isValidDirectives(char* str) {
    for(int i = 0; i < 5; i++){
        if(strcmp(str, directives[i]) == 0)
            return true; 
    }
    return false;
}


bool isValidHeaderFile(char *str){
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='.' && str[i+1] == 'h'){
			hfile_c++;
			return true;
		}		
	}
	return false;
}


bool isValidInteger(char* str) {
   int i, len = strlen(str);
   if (len == 0)
   return false;
   for (i = 0; i < len; i++) {
      if (!isdigit(str[i]) || (str[i] == '-' && i > 0))
      return false;
   }
   int_c++;
   return true;
}


bool isRealNumber(char* str) {
   int i, len = strlen(str);
   bool hasDecimal = false;
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (!isdigit(str[i]) && str[i] != '.' || (str[i] == '-' && i > 0))
      return (false);
      if (str[i] == '.'){
      		flt_c++;
    		hasDecimal = true;
	  }
   }
   return (hasDecimal);
}


char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2));
   for (i = left; i <= right; i++)
   subStr[i - left] = str[i];
   subStr[right - left + 1] = '\0';
   return (subStr);
}


void detectTokens(char* str) {
   int left = 0, right = 0;
   int length = strlen(str);
   while (right <= length && left <= right) {
      if (isValidDelimiter(str[right]) == false)
      right++;
      if (isValidDelimiter(str[right]) == true && left == right) {
        if (isValidOperator(str[right]) == true)
        printf("Valid operator : '%c'\n", str[right]);
        right++;
        left = right;
      } else if (isValidDelimiter(str[right]) == true && left != right || (right == length && left != right)) {
         char* subStr = subString(str, left, right - 1);
         if (isValidDirectives(subStr) == true)
         printf("Pre processors : '%s'\n", subStr);
         else if (isValidHeaderFile(subStr) == true)
         printf("Valid Header File : '%s'\n", subStr);
         else if (isValidKeyword(subStr) == true)
         printf("Valid keyword : '%s'\n", subStr);
         else if (isValidInteger(subStr) == true)
         printf("Valid Integer : '%s'\n", subStr);
         else if (isRealNumber(subStr) == true)
         printf("Real Number : '%s'\n", subStr);
         else if (isvalidIdentifier(subStr) == true
         && isValidDelimiter(str[right - 1]) == false)
         printf("Valid Identifier : '%s'\n", subStr);
         else if (isvalidIdentifier(subStr) == false
         && isValidDelimiter(str[right - 1]) == false)
         printf("Invalid Identifier : '%s'\n", subStr);
         left = right;
      }
   }
   return;
}


int main(){
	
	int i;    
   char str[10000];
   printf("Enter Program :");
	gets(str);
    
	printf("The Program is : '''%s'''\n\n", str);
	printf("All Tokens\n");
	detectTokens(str);
	printf("\n\nNo.of Identifiers: %d\n",iden_c);
	printf("No.of Operators: %d\n",oper_c);
	printf("No.of Keywords: %d\n",keyw_c);
	printf("No.of Integers: %d\n",int_c);
	printf("No.of Real Numbers: %d\n",flt_c);
	printf("No.of Header Files: %d\n",hfile_c);
   return 0;
}
