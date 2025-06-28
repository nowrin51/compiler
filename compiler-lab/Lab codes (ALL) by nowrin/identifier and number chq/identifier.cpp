#include<iostream>
using namespace std;
bool isValid(string str)
{
    int n=str.size();
    if((str[0]>='a'&&str[0]<='z')||(str[0]>='A'&&str[0]<='Z')||(str[0]=='_'))
    {
        for(int i=1;i<n;i++)
        {
            if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]=='_')||(str[i]>='0'&&str[i]<='9'));
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}
int main()
{
    string str;
    getline(cin,str);
    bool flag=isValid(str);
{
    if(flag==true)
    {
        cout<<"valid identifier"<<endl;
    }
    else
    {
        cout<<"Invalid identifier"<<endl;
    }
}
    return 0;
}


