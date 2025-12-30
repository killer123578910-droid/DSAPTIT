#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
vector<vector<int>> ar;
vector<bool> b;
vector<int> parent;
void dfs(int u)
{
    b[u] = true;
    for (auto x : ar[u])
    {
        if (!b[x])
        {
            dfs(x);
            parent[x] = u;
        }
    }
}
void timduongdd(int u, int v)
{
    dfs(u);
    if (b[v])
    {
        stack<int> st;
        int j = v;
        while (j != u)
        {
            st.push(j);
            j = parent[j];
        }
        st.push(u);
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
    else
    {
        cout << -1;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> u >> v;
        ar.assign(n + 1, vector<int>());
        b.assign(n + 1, false);
        parent.assign(n + 1, -1);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        timduongdd(u, v);
        cout << endl;
    }
    return 0;
}