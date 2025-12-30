//bài này yêu cầu liên tục()()
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
        stack<int> st;
        st.push(-1);
        int cnt = 0;
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {   
                st.pop();
                if (!st.empty())
                {
                  maxlen=max(maxlen, i-st.top());
                }
                else
                {
                   st.push(i);
                }
            }
        }
       maxlen = max(maxlen, cnt);
    
        cout << maxlen << endl;
    }

    return 0;
}