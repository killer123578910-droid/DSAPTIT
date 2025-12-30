#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int tt=1;
    while (t--)
    {
        string s;
        stack<int> st;
        cin >> s;
        int stt=1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'D')
            {
                st.push(stt);
                stt++;
            }
            else
            {
                st.push(stt);
                stt++;
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
            }
        }
        st.push(stt);
        while (!st.empty())
        {   
            cout << st.top();
            st.pop();
        }
        cout<<endl;
    }
    return 0;
}