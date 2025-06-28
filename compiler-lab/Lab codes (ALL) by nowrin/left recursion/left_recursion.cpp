 #include <bits/stdc++.h>
using namespace std;
int main()
{
    string prod[10];
    int i, j, k, n;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> prod[i];
    for (i = 0; i < n; i++)
    {
        string s = prod[i];
        string c = "\u03B5";

        char ch = s[0];
        int len = s.length();
        //vector<char> alpha;
        string alpha;
        cout << "\nGrammer: " << s;


        bool flag = false;
        if (s[3] == ch)
        {
            cout << " is left recursive.\n";
            for (j = 4; j < len; j++)
            {
               // E->E+T|T
                if (s[j] == '|')
                {
                    flag = true;
                    break;
                }
                alpha.push_back(s[j]); // +T
            }
            if (flag)
            {
                cout << ch << "->";
                for (k = j + 1; k < len; k++)
                    cout << s[k];
                cout << ch << "`\n"
                     << ch << "`->";
                for (j = 0; j < alpha.size(); j++)
                    cout << alpha[j];
                cout << ch << "`|" << c << endl;
            }
            else
            {
                cout << ch << "->" << ch << "`\n"
                     << ch << "`->";
                for (j = 0; j < alpha.size(); j++)
                    cout << alpha[j];
                cout << ch << "`|" << c << endl;
            }
        }
        else
            cout << " is not left recursive.\n";
    }
    return 0;
}

/*
Input:
3
E->E+T
E->T*F|F
F->(E)|x|y

Output:

Grammer: E->E+T|T is left recursive.
E->TE`
E`->+TE`|ε

Grammer: E->T*F|F is not left recursive.

Grammer: F->(E)|x|y is not left recursive.
*/




