%{
#include<stdio.h>
#include<string.h>
char line[100];
%}
/* Rule Section */
/* Rule 1 writes the string stored in line
character array to file output.txt */
/* Rule 2 copies the matched token i.e every character except newline
character
to line character array */
%%
\/\/(.*) {};
\/\(.\n).\*\/ {};
['\n'] { fprintf(yyout,
"%s\n"
,line);
printf("%s"
,line);}
%%
/*['\n'] { fprintf(yyout,
"%s\n"
,line);
printf("%s"
,line);}
<<EOF>> { fprintf(yyout,
"%s"
,line); printf("%s"
,line); return 0;}*/
int yywrap()
{
return 1;
}
/* code section */
int main()
{
extern FILE *yyin,
*yyout;
yyin=fopen("input1.txt"
,
"r");
yyout=fopen("out.txt"
,
"w"); yylex();}