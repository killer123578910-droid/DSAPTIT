#include <bits/stdc++.h>
using namespace std;
int ar[21];
vector<int> a;
int n;
set<string> st;
void in()
{
    if (a.size() >= 2)
    {
        string temp;
        for (auto x : a)
        {
            temp += to_string(x);
            temp += " ";
        }
        st.insert(temp);
    }
}
void quaylui(int i)
{
    if (i == n)
    {
        in();
        return;
    }
    if (a.empty())
    {
        quaylui(i + 1);
        a.push_back(ar[i]);
        quaylui(i + 1);
        a.pop_back();
    }
    else
    {
        if (ar[i] > a[a.size()-1])
        {
            quaylui(i + 1);
            a.push_back(ar[i]);
            quaylui(i + 1);
            a.pop_back();
        }
        else
        {
            quaylui(i + 1);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    quaylui(0);
    for (auto x : st)
        cout << x << endl;
    return 0;
}