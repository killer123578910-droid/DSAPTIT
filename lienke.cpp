#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string removezero(string s)
{
    int i = 0;
    while (i < s.size() - 1 && s[i] == '0')
    {
        i++;
    }
    return s.substr(i);
}
bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();

    vector<string> s4;
    string s2;

    for (int i = 0; i < t; i++)
    {
        string temp;
        getline(cin, temp);

        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] >= '0' && temp[j] <= '9')
            {
                s2 += temp[j];
            }
            else
            {
                if (!s2.empty())
                {
                    s4.push_back(removezero(s2));
                    s2.clear();
                }
            }
        }
        if (!s2.empty())
        {
            s4.push_back(removezero(s2));
            s2.clear();
        }
    }
    sort(s4.begin(), s4.end(), cmp);
    for (auto x : s4)
        cout << x << endl;

    return 0;
}
