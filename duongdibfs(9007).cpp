#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
vector<vector<int>> ar;
vector<bool> b;
vector<int> parent;
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    b[u] = true;
    while (!q.empty())
    {
        int x = q.front();q.pop();
        for (auto k : ar[x])
        {
            if (!b[k])
            {
                b[k] = true;
                q.push(k);
                parent[k] = x;
            }
        }
    }
}
void timduongdd(int u, int v)
{
    bfs(u);
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