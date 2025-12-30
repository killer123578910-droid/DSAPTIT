#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        stack<char> st;
        int open = 0, close = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                open++;
            }
            else
            {
                if (!st.empty() && st.top() =='(')
                {
                    st.pop();
                    open--;
                }else{
                    close++;
                    st.push(s[i]);
                }
            }
        }
        int ans=open/2+close/2;
        ans+=open%2+close%2;
        cout<<ans<<endl;
    }
    return 0;
}