#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        vector<vector<int>> ar(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> ar[i][j];
            }
        }
        vector<int> height(m, 0), l(m), r(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ar[i][j])
                    height[j]++;
                else
                    height[j] = 0;
            }
            stack<int> st;
            for (int i = 0; i < m; i++)
            {
                while (!st.empty() && height[i] <= height[st.top()])
                {
                    st.pop();
                }
                if (st.empty())
                    l[i] = -1;
                else
                    l[i] = st.top();
                st.push(i);
            }
            while (!st.empty())
                st.pop();
            for (int i = m - 1; i >= 0; i--)
            {
                while (!st.empty() && height[i] <= height[st.top()])
                {
                    st.pop();
                }
                if (st.empty())
                    r[i] = m;
                else
                    r[i] = st.top();
                st.push(i);
            }
            for (int i = 0; i < m; i++)
            {
                ans = max(ans, (r[i] - l[i] - 1) * height[i]);
            }
        }

        cout << ans << endl;
    }
}