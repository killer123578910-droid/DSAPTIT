#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> ar(1005);
vector<int> color(1005);
bool bfs(int u)
{
    queue<int> q;
    q.push(u);
    color[u] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto x : ar[t])
        {
            if (color[x] == -1)
            {
                color[x] = color[t] == 0 ? 1 : 0;
                q.push(x);
            }
            else if (color[x] == color[t])
            {
                return false;
            }
            
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for(int i=0;i<=n;i++){
            ar[i].clear();
            color[i]=-1;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        int check = 1;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(i))
                {

                    check = 0;
                    break;
                }
            }
        }
        cout<<(check?"YES":"NO")<<endl;
    }
    return 0;
}