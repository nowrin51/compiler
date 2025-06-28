#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,s1;
    cin>>s;
    vector<string> v;

    for(int i=3; i<s.size(); i++)
    {
        if(s[i]!='|')
        {
            s1+=s[i];//b
        }
        else
        {
            v.push_back(s1);
            s1="";
        }
    }
    v.push_back(s1);

    string ne,ne1="cvbnmijuhgcvbnkjh";
    string k=v[0];//bssaas
    for(int i=1; i<v.size(); i++)
    {
        string m=v[i];//bsb
        for(int j=0; j<m.size(); j++)
        {
            if(k[j]==m[j])
            {
                ne+=m[j];
            }
            else
            {
                j=m.size()-1;
            }
        }
        if(ne.size()<ne1.size() && ne!="")
        {
            ne1=ne;
        }
        ne="";
    }
    for(int i=0; i<3; i++)
    {
        cout<<s[i];
    }
    cout<<ne1<<s[0]<<'`';
    for(int i=0; i<v.size(); i++)
    {
        string k=v[i];
        int c=0;
        for(int j=0; j<ne1.size(); j++)
        {
            if(k[j]==ne1[j])
            {
                c++;
            }
        }
       // if(c!=ne1.size())
       // {
            //cout<<'|'<<k;
         //   v[i]='0';
       // }
    }
    cout<<endl;
    cout<<s[0]<<"`->";
    for(int i=0; i<v.size(); i++)
    {
        string p=v[i];
        int c=0;
        for(int j=0; j<ne1.size(); j++)
        {
            if(p[j]==ne1[j])
            {
                size_t pos = v[i].find(ne1);
                if (pos != std::string::npos)
                {
                    v[i].erase(pos, ne1.length());
                    j=ne1.size()-1;
                }
            }
        }
    }
    for(auto x:v)
    {
        if(x=="")
            cout<<'#'<<'|';
        else if(x!="0")
        {
            cout<<x<<'|';

        }
    }
}
//S->a|ab|abc|abcd
//S->iets|ietses|a
//S->bSSaaS|bSSaSb|bSb|a
//A->aAB|aBc|aAc
//S->aSSbS|aSaSb|abb|b
