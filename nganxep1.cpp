#include <bits/stdc++.h>
using namespace std;
void show(stack<int> st)
{
    stack<int> temp = st;
    vector<int> t;
    while (!temp.empty())
    {
        t.push_back(temp.top());
        temp.pop();
    }
    reverse(t.begin(), t.end());
    for (auto x : t)
        cout << x << " ";
    cout << endl;
}
int main()
{
    string s;
    int n;
    stack<int> st;
    while (cin >> s)
    {
        if (s == "push")
        {
            cin >> n;
            st.push(n);
        }
        else if (s == "show")
        {
            if (!st.empty())
                show(st);
            else
                cout << "empty" << endl;
        }
        else if (s == "pop")
        {
            if (!st.empty())
                st.pop();
        }
    }
    return 0;
}