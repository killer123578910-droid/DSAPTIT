#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> ar(1005);
vector<int> b(1005);
int flag = 0;
void dfs(int u)
{
    b[u] = 1;
    for (auto v : ar[u])
    {
        if (flag)
            return;
        if (!b[v])
        {
            dfs(v);
        }
        else if (b[v] == 1)
        {
            flag = 1;
            return;
        }
    }
    b[u] = 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            ar[i].clear();
            b[i] = 0;
        }
        flag = 0;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!b[i])
            {
                dfs(i);
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}