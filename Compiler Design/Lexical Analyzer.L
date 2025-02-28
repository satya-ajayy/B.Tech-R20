%{
    int COMMENT=0;
%}

identifier      [a-zA-Z_][a-zA-Z0-9_]*
keyword         "int"|"float"|"char"|"while"|"double"|"if"|"else"|"return"|"case"|"switch"|"goto"|"long"|"void"|"break"
assignment      "="
relational      "<"|">"|"<="|">="|"=="
string          \".*\"
number          [0-9]+


%%

"/*" {COMMENT = 1;}
"*/" {COMMENT = 0;}

#.*             {if(!COMMENT) printf("\n%s is a PREPROCESSOR DIRECTIVE",yytext);}
{keyword}       {if(!COMMENT) printf("\n\t%s is a KEYWORD",yytext);}
{assignment}    {if(!COMMENT) printf("\n\t%s is an ASSIGNMENT OPERATOR",yytext);}
{relational}    {if(!COMMENT) printf("\n\t%s is a RELATIONAL OPERATOR",yytext);}
{string}        {if(!COMMENT) printf("\n\t%s is a STRING",yytext);}
{number}        {if(!COMMENT) printf("\n\t%s is a NUMBER",yytext);}
{identifier}\(  {if(!COMMENT) printf("\n\nFUNCTION\n\t%s",yytext);}
\{              {if(!COMMENT) printf("\n BLOCK BEGINS");}
\}              {if(!COMMENT) printf("\n BLOCK ENDS");}
{identifier}(\[[0-9]*\])?   {if(!COMMENT) printf("\n %s IDENTIFIER",yytext);}
\)(\;)?                     {if(!COMMENT) printf("\n\t");ECHO;printf("\n");}
\( ECHO;

%%


int main(int argc,char **argv)
{
    if (argc > 1)
    {
        FILE *file;
        file = fopen(argv[1],"r");
        if(!file)
        {
            printf("could not open %s \n",argv[1]);
            exit(0);
        }
        yyin = file;
    }
    yylex();
    return 0;
}
int yywrap()
{
    return 1;
}
