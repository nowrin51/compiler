%{
#include <stdio.h>
#include <stdlib.h>

// Define tokens
#define KEYWORD     1
#define IDENTIFIER  2
#define NUMBER      3
#define OPERATOR    4
#define PUNCTUATION 5
#define UNKNOWN     6
%}

// Define keywords
KEYWORD      int|return|printf|scanf
IDENTIFIER   [a-zA-Z_][a-zA-Z0-9_]*
NUMBER       [0-9]+
OPERATOR     [+\-*/%=<>!&|^~]
PUNCTUATION  [;,(){}]

%%

{KEYWORD}     { printf("Keyword: %s\n", yytext); }
{IDENTIFIER}  { printf("Identifier: %s\n", yytext); }
{NUMBER}      { printf("Number: %s\n", yytext); }
{OPERATOR}    { printf("Operator: %s\n", yytext); }
{PUNCTUATION} { printf("Punctuation: %s\n", yytext); }
\n            { /* Ignore newline */ }
[ \t\r]+      { /* Ignore whitespace */ }
.             { printf("Unknown: %s\n", yytext); }

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Could not open file");
            return EXIT_FAILURE;
        }
        yyin = file;
    }
    yylex();
    return 0;
}
