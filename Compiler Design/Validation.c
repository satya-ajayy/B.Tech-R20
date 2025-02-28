#include <stdio.h>
#include <ctype.h>

int is_delimiter(char ch) {
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return 1;
    return 0;
}


int main() {
    int i,count=0,length=0,start=0;
    char A[100];
    printf("Enter a string : ");
    scanf("%[^\n]s", A);
    for (i = 0; A[i] != '\0'; i++) {
        if (A[i] == '"'){
            start++;
            count++;
        }
        if (is_delimiter(A[i]) || isalpha(A[i]) || isdigit(A[i]))
            count++;
        length++;  
    }
    if (length == count && start % 2 == 0) printf("Valid String", A);
    else printf("Invalid String", A);

return 0;
}
