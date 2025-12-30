#include <bits/stdc++.h>
using namespace std;
int n, m, u, k, q;
vector<int> ar[1005];
vector<bool> vi;
vector<int> parent(1005);
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    vi[u] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto x : ar[temp])
        {
            if (!vi[x])
            {
                vi[x] = true;
                q.push(x);
                parent[x] = temp;
            }
        }
    }
}
void tracing(int u, int k, int n)
{
    vi.assign(n + 1, false);
    parent.assign(n + 1, -1);
    bfs(u);
    if (!vi[k])
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= 1004; i++)
            ar[i].clear();
        vi.assign(n + 1, false);
        parent.assign(n + 1, -1);
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }

        int q;
        cin >> q;
        vector<pair<int, int>> qe(q);
        for (int i = 0; i < q; i++)
        {
            cin >> u >> k;
            qe[i] = {u, k};
        }
        for (int i = 0; i < q; i++)
        {
            tracing(qe[i].first, qe[i].second, n);
        }
    }
    return 0;
}