#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &ar, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        // Nếu đến đích rồi -> thoát
        if (x == n - 1 && y == m - 1) break;

        // ↓ Đi xuống
        if (x + 1 < n)
        {
            int step = abs(ar[x + 1][y] - ar[x][y]);
            int nx = x + step;
            if (nx < n && !visited[nx][y])
            {n
                visited[nx][y] = true;
                parent[nx][y] = {x, y};
                q.push({nx, y});
            }
        }

        // → Đi sang phải
        if (y + 1 < m)
        {
            int step = abs(ar[x][y + 1] - ar[x][y]);
            int ny = y + step;
            if (ny < m && !visited[x][ny])
            {
                visited[x][ny] = true;
                parent[x][ny] = {x, y};
                q.push({x, ny});
            }
        }

        // ↘ Đi chéo
        if (x + 1 < n && y + 1 < m)
        {
            int step = abs(ar[x + 1][y + 1] - ar[x][y]);
            int nx = x + step, ny = y + step;
            if (nx < n && ny < m && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!visited[n - 1][m - 1])
    {
        cout << -1 << endl;
        return;
    }

    // Đếm số bước
    int steps = 0;
    pair<int, int> cur = {n - 1, m - 1};
    while (cur != make_pair(0, 0))
    {
        steps++;
        cur = parent[cur.first][cur.second];
    }

    cout << steps << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ar(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> ar[i][j];

        bfs(ar, n, m);
    }
}
