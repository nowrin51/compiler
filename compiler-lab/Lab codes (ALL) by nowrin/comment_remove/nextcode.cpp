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
  break;  } else if (!inSingleLineComment && !inMultiLineComment && line[i] == '/' && i + 1 <
line.length() && line[i + 1] == '*') {
  inMultiLineComment = true;
 ++i;  } else if (inMultiLineComment && line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/')
{
  inMultiLineComment = false;
 ++i;  } else if (!inSingleLineComment && !inMultiLineComment) {
 
 result += line[i];
 }
 }
  cout << result << endl;
 }
 return 0;
}
