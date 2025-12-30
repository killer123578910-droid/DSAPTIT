#include <bits/stdc++.h>
using namespace std;
int n, m, u;
vector<int> ar[1005];
vector<bool> vi;
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    vi[u] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for (auto x : ar[temp])
        {
            if (!vi[x])
            {
                vi[x] = true;
                q.push(x);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> u;
        for (int i = 1; i <= 1004; i++)
            ar[i].clear();
        vi.assign(n + 1, false);
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
        }
        bfs(u);
        cout << endl;
    }
    return 0;
}