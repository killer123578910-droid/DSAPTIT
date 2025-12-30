#include <bits/stdc++.h>
using namespace std;
stack<string> st;
void tamgiac(int n, vector<int> &a)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = a[i] + a[i + 1];
    }
    n--;
    string temp;
    temp += "[";
    for (int i = 0; i < n; i++)
    {
        temp += to_string(a[i]);
        if (i != n - 1)
            temp += " ";
    }
    temp += "]";
    st.push(temp);
    tamgiac(n, a);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        string temp;
        temp += "[";
        for (int i = 0; i < n; i++)
        {
            temp += to_string(ar[i]);
            if (i != n - 1)
                temp += " ";
        }
        temp += "]";
        st.push(temp);
        tamgiac(n, ar);
        while (!st.empty())
        {
            string in = st.top();
            st.pop();
            cout << in<<" ";
        }
        cout<<endl;
    }
    return 0;
}