#include <bits/stdc++.h>
using namespace std;

vector<int> tin, low;
vector<pair<int, int>> res;
vector<bool> vi;
int timer;

void dfs(int u, int parent, vector<int> ar[]) {
    vi[u] = true;
    tin[u] = low[u] = timer++;

    for (int v : ar[u]) {
        if (v == parent) continue;

        if (!vi[v]) {
            dfs(v, u, ar);
            low[u] = min(low[u], low[v]);

            if (low[v] > tin[u]) {
                res.push_back({min(u, v), max(u, v)});
            }
        } 
        else {
            low[u] = min(low[u], tin[v]);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> ar[n + 1];
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }

        timer = 0;
        res.clear();
        tin.assign(n + 1, -1);
        low.assign(n + 1, -1);
        vi.assign(n + 1, false);

        for (int i = 1; i <= n; i++) {
            if (!vi[i]) {
                dfs(i, -1, ar);
            }
        }

        sort(res.begin(), res.end());

        for (auto &p : res) {
            cout << p.first << " " << p.second << " ";
        }
        cout << "\n";
    }

    return 0;
}
