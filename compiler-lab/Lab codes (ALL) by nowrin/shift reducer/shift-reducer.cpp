#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout << "number of productions: "<<n<<endl;
    cout <<endl;
    vector<pair<char,string>> gram(10);
    cout << "productions:\n";
    for (int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        gram[i].first = s[0];
        gram[i].second = s.substr(3);
    }
    cout << "\nEnter input:\n";
    char input[10],stack[10];
    cin>>input;
    int len = strlen(input);
    int i=0,st_pos=0,r;

    stack[st_pos]=input[i];
    i++,st_pos++;
    cout << setw(30) << "\nstack\t\tInput\t\tAction\n";
    do
    {
        r=1;
        while(r!=0)
        {
            cout <<endl;
            for (int j=0;j<st_pos;j++)//stack ar size prjnto print
                cout << stack[j];
            cout << setw(3)<<"\t";
            for (int j=i;j<len;j++)
                cout << input[j];
            cout<<setw(9)<<"\t";
            if(r==2)
                cout << setw(7)<<"reduced";
            else
                cout <<setw(7)<<"shifted";
            r=0;
            for (int j=0;j<st_pos;j++)//reduce krar try krbo
            {
                char ts[10];
                for (int l=0;l<10;l++)
                    ts[l]='\0';
                int ts_pos=0,l;
                for (int k=j;k<st_pos;k++)//removing 1st char
                {
                    ts[ts_pos]=stack[k];
                    ts_pos++;
                }
                ts[ts_pos]='\0';
                for (int k=0;k<n;k++)
                {
                    string tmp= gram[k].second;
                    if (ts==tmp)
                    {
                        for (l=j;l<10;l++)//removing match part
                            stack[l]='\0';
                        stack[j]= gram[k].first;//non terminal
                        st_pos=j+1,r=2;
                    }
                }
            }
        }
        stack[st_pos]=input[i];//stack e abar input newa
        i++,st_pos++;
    }
    while (strlen(stack)!=1 &&st_pos!=len);
    if (strlen(stack)==1)
    printf("\nAccepted\n");
    else
        printf("\nNot Accepted");
    return 0;
}

/*
input gramer:
3
S->SS+
S->SS*
S->a
input string:
aaa*a++


E->E-E
E->E*E
E->id

E->E+T
E->T
T->int



*/

