%{
#include <iostream>
using namespace std;
%}

/* Definitions*/
letter [a-zA-Z]
digit [0-9]
underscore _

/* Rules*/
%%
{letter}({letter}|{digit}|{underscore})* {
    cout << "Valid identifier" << endl;
}

.|\n {
    /* Ignore other characters*/
}

%%

int main() {
    yylex();
    return 0;
}
