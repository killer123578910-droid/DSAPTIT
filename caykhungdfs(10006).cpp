#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int sc = 0;
vector<vector<int>> ar(1005);
vector<bool> b(1005);
vector<pair<int, int>> t;
void dfs(int u)
{
    stack<int> st;
    st.push(u);
    b[u] = true;
    while (!st.empty())
    {
        int te = st.top();
        st.pop();
        for (int i : ar[te])
        {
            if (!b[i])
            {
                t.push_back({te, i});
                sc++;
                b[i] = true;
                st.push(te);
                st.push(i);
                break;
            }
        }
    }
    if (sc < n - 1)
        cout << -1 << endl;
    else
    {
        for (auto x : t)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
}
int main()
{
    int e;
    cin >> e;
    while (e--)
    {
        cin >> n >> m >> k;
        for (int i = 0; i <= n; i++)
        {
            ar[i].clear();
            b[i] = false;
        }
        t.clear();
        sc = 0;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        dfs(k);
    }
    return 0;
}