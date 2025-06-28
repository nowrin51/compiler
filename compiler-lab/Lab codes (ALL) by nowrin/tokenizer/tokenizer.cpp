#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATION,
    TOKEN_UNKNOWN,
    TOKEN_END_OF_FILE
} TokenType;

typedef struct {
    TokenType type;
    char value[100];
} Token;

const char *keywords[] = {
    "int", "return", "printf", "scanf"
};
const int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

int is_keyword(const char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_operator(char c) {
    return strchr("+-*/%=<>!&|^~", c) != NULL;
}

int is_punctuation(char c) {
    return strchr(";,(){}[]", c) != NULL;
}

void get_next_token(FILE *file, Token *token) {
    char c;
    int index = 0;

    // Skip whitespaces
    while (isspace(c = fgetc(file)));

    if (c == EOF) {
        token->type = TOKEN_END_OF_FILE;
        strcpy(token->value, "EOF");
        return;
    }

    if (isalpha(c) || c == '_') { // Identifier or Keyword
        do {
            token->value[index++] = c;
            c = fgetc(file);
        } while (isalnum(c) || c == '_');
        ungetc(c, file);
        token->value[index] = '\0';
        token->type = is_keyword(token->value) ? TOKEN_KEYWORD : TOKEN_IDENTIFIER;
    } else if (isdigit(c)) { // Number
        do {
            token->value[index++] = c;
            c = fgetc(file);
        } while (isdigit(c));
        ungetc(c, file);
        token->value[index] = '\0';
        token->type = TOKEN_NUMBER;
    } else if (is_operator(c)) { // Operator
        token->value[index++] = c;
        c = fgetc(file);
        if (is_operator(c)) { // Check for two-character operators
            token->value[index++] = c;
        } else {
            ungetc(c, file);
        }
        token->value[index] = '\0';
        token->type = TOKEN_OPERATOR;
    } else if (is_punctuation(c)) { // Punctuation
        token->value[index++] = c;
        token->value[index] = '\0';
        token->type = TOKEN_PUNCTUATION;
    } else { // Unknown
        token->value[index++] = c;
        token->value[index] = '\0';
        token->type = TOKEN_UNKNOWN;
    }
}

int main() {
    // Sample input C code as a string
    const char *input_code = "#include<stdio.h>\n"
                             "int main()\n"
                             "{\n"
                             "    int a, b, c;\n"
                             "    printf(\"enter two numbers: \");\n"
                             "    scanf(\"%d%d\", &a, &b);\n"
                             "    c = a + b;\n"
                             "    printf(\"%d\", c);\n"
                             "    return 0;\n"
                             "}";

    // Write the input code to a temporary file
    const char *input_filename = "input.c";
    FILE *input_file = fopen(input_filename, "w");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }
    fputs(input_code, input_file);
    fclose(input_file);

    // Reopen the file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    Token token;
    do {
        get_next_token(input_file, &token);
        switch (token.type) {
            case TOKEN_KEYWORD:
                printf("Keyword: %s\n", token.value);
                break;
            case TOKEN_IDENTIFIER:
                printf("Identifier: %s\n", token.value);
                break;
            case TOKEN_NUMBER:
                printf("Number: %s\n", token.value);
                break;
            case TOKEN_OPERATOR:
                printf("Operator: %s\n", token.value);
                break;
            case TOKEN_PUNCTUATION:
                printf("Punctuation: %s\n", token.value);
                break;
            case TOKEN_UNKNOWN:
                printf("Unknown: %s\n", token.value);
                break;
            case TOKEN_END_OF_FILE:
                printf("End of file\n");
                break;
        }
    } while (token.type != TOKEN_END_OF_FILE);

    fclose(input_file);
    return EXIT_SUCCESS;
}

