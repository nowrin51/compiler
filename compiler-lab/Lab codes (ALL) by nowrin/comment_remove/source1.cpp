#include <iostream>
#include <string>
using namespace std;
int main() {
 string line;
 bool inSingleLineComment = false;
 bool inMultiLineComment = false;
 while (getline(cin, line)) {
 string result;
 for (size_t i = 0; i < line.length(); ++i) {
 if (!inSingleLineComment && !inMultiLineComment && line[i] == '/' && i + 1 <
line.length() && line[i + 1] == '/') {
 // Start of single-line comment
 break; // Skip the rest of the line
 } else if (!inSingleLineComment && !inMultiLineComment && line[i] == '/' && i + 1 <
line.length() && line[i + 1] == '*') {
 // Start of multi-line comment
 inMultiLineComment = true;
 ++i; // Skip the next character '*'
 } else if (inMultiLineComment && line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/')
{
 // End of multi-line comment
 inMultiLineComment = false;
 ++i; // Skip the next character '/'
 } else if (!inSingleLineComment && !inMultiLineComment) {
 /* Not in comment, add character to result*/
 result += line[i];
 }
 }
 // Output the result without comments
 cout << result << endl;
 }
 return 0;
}
