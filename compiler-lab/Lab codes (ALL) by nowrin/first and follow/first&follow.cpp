#include <bits/stdc++.h>
using namespace std;
string eps = "\u03B5";
vector< pair<char, string> > gram(10);
string ans;
int n, m = 0;
void follow(char c);
void follow_first(char c);
void add_result(char c);
void first(char c)
{
    for (int i = 0; i < n; i++)
    {
        if (gram[i].first == c)
        {
            string s2 = gram[i].second;
            int len2 = s2.length();
            for (int j = 0; j < len2; j++)
            {
                if (j == 0)
                {
                    if (isupper(s2[j]))
                        first(s2[j]);
                    else
                    {
                        if (s2[j]=='i' && s2[j + 1]=='d') //if terminal and also length 2
                            cout << s2 [j] << s2[j + 1] << ", ";
                        else if (s2[j] == '&') //printing epsilon
                            cout << eps << " ";
                        else
                            cout << s2[j] << ", "; //if terminal
                    }
                }
                else if (s2[j - 1] == '|')
                    if (isupper(s2[j]))
                        first(s2[j]);
                    else
                    {
                        if (s2[j]=='i' && s2[j + 1]=='d') //if terminal and also length 2
                            cout << s2[j] << s2[j + 1] << ", ";
                        else if (s2[j] == '&') //printing epsilon
                            cout << eps << " ";
                        else
                            cout << s2[j] << ", "; //if terminal
                    }
            }
        }
    }
}
int main()
{
    cin>>n;
    cout<<"Number of productions: "<<n<<endl;
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        gram[i].first = s[0];
        gram[i].second = s.substr(3);
    }
    gram.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "First of " << gram[i].first << " : { ";
        string s = gram[i].second;
        int len = s.length();
        for (int j = 0; j < len; j++)
        {
            if (j == 0)
            {
                if (isupper(s[j]))
                    first(s[j]);
                else
                {
                    if (s[j]=='i' && s[j + 1]=='d') //if terminal and also length 2
                        cout << s[j] << s[j + 1] << ", ";
                    else if (s[j] == '&') //printing epsilon
                        cout << eps << " ";
                    else
                        cout << s[j] << ", "; //if terminal
                }
            }

            else if (s[j - 1] == '|')
                if (isupper(s[j])) // if non-terminal
                    first(s[j]);
                else
                {
                    if (s[j]=='i' && s[j + 1]=='d') //if terminal and also length 2
                        cout << s[j] << s[j + 1] << ", ";
                    else if (s[j] == '&') //printing epsilon
                        cout << eps << " ";
                    else
                        cout << s[j] << ", "; //if terminal
                }
        }
        cout<<"}\n";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        m=0;
        cout << "Follow of " << gram[i].first << " : { ";
        ans.clear();
        follow(gram[i].first);
        for (int j = 0; j < m; j++)
            cout<<ans[j]<<", ";
        cout<<"}\n";
    }
    return 0;
}

void add_result(char c)
{
    for (int i = 0; i < m; i++)
        if (ans[i] == c) //if previously calculated then return
            return;
    if (c != '&' && c != '|') //adding result
        ans+=c,m++;
}
void follow_first(char c)
{
    if (!isupper(c) && c != '|' && c != '&') //if terminal
        add_result(c);
    for (int i = 0; i < n; i++)
    {
        string s = gram[i].second;
        int len = s.length();
        if (gram[i].first == c)
        {
            for (int j = 0; j < len; j++)
            {
                if (j == 0)
                {
                    if (isupper(s[j])) //non-terminal
                        follow_first(s[j]);
                    else
                        add_result(s[j]);
                }
                else if (s[j - 1] == '|')
                {
                    if (s[j] == '&')
                        follow(gram[i].first); //if epsilon
                    if (isupper(s[j]))
                        follow_first(s[j]); //if non-terminal
                    else
                        add_result(s[j]); // if terminal
                }
            }
        }
    }
}
void follow(char c)
{
    if (c == gram[0].first) //if non-terminal
        add_result('$');
    for (int i = 0; i < n; i++)
    {
        string s = gram[i].second;
        int len = s.length();
        for (int j = 0; j < len; j++)
            if (s[j] == c)
            {
                if (((j + 1) == len || s[j + 1] == '|') && c != gram[i].first) //if non-terminal but the first of RHS
                    follow(gram[i].first);
                else
                    follow_first(s[j + 1]);
            }
    }
}

/*
Input:
5
E->TX
X->+TX|&
T->FY
Y->*FY|&
F->(E)|id

Output:
First of E : { (, id, }
First of X : { +, ε }
First of T : { (, id, }
First of Y : { *, ε }
First of F : { (, id, }

Follow of E : { $, ), }
Follow of X : { $, ), }
Follow of T : { +, $, ), }
Follow of Y : { +, $, ), }
Follow of F : { *, +, $, ), }
*/


