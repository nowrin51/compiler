#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *f1,*f2;
    char ch,ch2;
    f1=fopen("source1.cpp","r");
    f2=fopen("nextcode.cpp","w");
    if(f1==NULL)
    {
        cout<<"null"<<endl;
    }
    else
    {
        while((ch=fgetc(f1))!=EOF)
        {
            if(ch=='/')
            {
                ch2=fgetc(f1);
                if(ch2=='/')
                {
                    while(ch2!='\n')
                    {
                        ch2=fgetc(f1);
                    }
                }
                else if(ch2=='*')
                {
                    while(ch2!='/')
                    {
                        ch2=fgetc(f1);
                    }
                }
                else
                {
                    cout<<ch<<ch2;
                    fputc(ch,f2);
                    fputc(ch2,f2);
                }
            }
            else{
                cout<<ch;
                fputc(ch,f2);
            }
        }
    }
    fclose(f1);
    fclose(f2);
}
