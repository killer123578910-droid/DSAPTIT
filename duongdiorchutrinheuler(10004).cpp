#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> ar(1005);
vector<bool> b(1005);
map<int, int> cap;
int cc = 0;
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    b[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto x : ar[v])
        {
            if (!b[x])
            {
                q.push(x);
                b[x] = true;
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
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            ar[i].clear();
            b[i] = false;
        }
        cap.clear();
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
            ar[y].push_back(x);
            cap[x]++;
            cap[y]++;
        }
        cc = 0;
        int flag1 = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!b[i])
            {
                cc++;
                bfs(i);
            }
            if (cc > 2)
            {
                flag1 = 0;
                break;
            }
        }
        if (!flag1)
            cout << "0" << endl;
        else
        {
            int flag2 = 1;
            vector<int> semi;
            for (int i = 1; i <= n; i++)
            {
                if (cap[i] % 2 != 0)
                {
                    flag2 = 0;
                    semi.push_back(i);
                }
            }
            if (flag2)
                cout << "2" << endl;
            else
            {
                if (semi.size() > 2)
                    cout << "0" << endl;
                else
                {
                    cout << "1" << endl;
                }
            }
        }
    }
    return 0;
}