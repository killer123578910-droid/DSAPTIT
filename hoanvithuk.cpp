#include <bits/stdc++.h>
using namespace std;
int ar[11], b[11], n, k;
string s;
string s1;
set<string> ss;
void in()
{
    for (int i = 1; i <= n; i++)
    {
        s1.push_back(s[ar[i]]);
    }
    ss.insert(s1);
    s1.clear();
}
void quaylui(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (b[j] == 0)
        {
            b[j] = 1;
            ar[i] = j;
            if (i == n)
                in();
            else
                quaylui(i + 1);
            b[j] = 0;
        }
    }
}
int main()
{

    cin >> s >> k;
    if (k == 0)
        cout << s << endl;
    else
    {
        n = s.size();
        s = '0' + s;
        quaylui(1);

        int count = 0;

        if (k >= 1 && k <= (int)ss.size())
        {
            auto it = ss.begin();
            advance(it, k - 1);
            cout << *it << endl;
        }   
    }

    return 0;
}
