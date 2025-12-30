#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ar[100001];
int n, m, u;
void dijktra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, u});
    vector<long long> d(n + 1, LLONG_MAX);
    d[u] = 0;
    while (!q.empty())
    {
        pair<int, int> te = q.top();
        q.pop();
        int kc = te.first;
        int v = te.second;
        if (kc > d[v])
            continue;
        for (auto i : ar[v])
        {
            int k = i.first;
            int l = i.second;
            if (d[k] > d[v] + l)
            {
                d[k] = d[v] + l;
                q.push({d[k], k});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> u;
        for (int i = 0; i <= n; i++)
            ar[i].clear();
        for (int i = 0; i < m; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            ar[x].push_back({y, w});
            ar[y].push_back({x, w});
        }
        dijktra();
        cout << endl;
    }
    return 0;
}