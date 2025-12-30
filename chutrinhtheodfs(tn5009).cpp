#include <bits/stdc++.h>
using namespace std;
int n, m;
bool ok = false;
vector<vector<int>> ar(1005);
vector<bool> b(1005);
string res;
void dfs(int u, string s, int par)
{
    if (ok)
        return;
    b[u] = true;
    for (auto x : ar[u])
    {
        if (!b[x])
            dfs(x, s + " " + to_string(x), u);
        else if (x != par && x == 1)
            ok = true, res = s;
    }
}
int main()
{
    int e;
    cin >> e;
    while (e--)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            ar[i].clear();
            b[i] = false;
        }
        ok = false;
        res.clear();
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        for(int i=1;i<=n;i++) sort(ar[i].begin(),ar[i].end());
        dfs(1, "1", 0);
        if (ok)
            cout << res << " " << 1 << endl;
        else
            cout <<"NO"<<endl;
    }
    return 0;
}