//bai nay khong yeu cau lien tuc;
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
        stack<char> st;
        int cnt = 0;
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++)
        {  
            if(s[i]==')'&&!st.empty()&&st.top()=='('){
                st.pop();
            }
            else st.push(s[i]);
        }
          cout <<s.size()-st.size() << endl;
    }
    return 0;
}