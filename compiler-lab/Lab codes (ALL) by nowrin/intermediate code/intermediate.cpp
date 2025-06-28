#include <stdio.h>
#include <string.h>
typedef struct
{
 char op[5];
 char arg1[5];
 char arg2[5];
 char result[5];
}
 Instruction;
#define MAX_INSTRUCTIONS 10
Instruction code[MAX_INSTRUCTIONS];
int instructionCount = 0;
void addInstruction(const char* op, const char* arg1, const char* arg2, const char* result)
 {
 strcpy(code[instructionCount].op, op);
 strcpy(code[instructionCount].arg1, arg1);
 if (arg2 != NULL)
    {
        strcpy(code[instructionCount].arg2, arg2);
    }
 else
    {
        strcpy(code[instructionCount].arg2, "");
    }
 strcpy(code[instructionCount].result, result);
 instructionCount++;
 }
void printIntermediateCode()
{
 for (int i = 0; i < instructionCount; i++) {
 printf("%s = %s %s %s\n", code[i].result, code[i].arg1, code[i].op, code[i].arg2);
 }
}
int main()
 {
 char tempVar1[5] = "t1";
 char tempVar2[5] = "t2";
 addInstruction("*", "b", "c", tempVar1);
 addInstruction("+", "a", tempVar1, tempVar2);
 printIntermediateCode();
 return 0;
 }
