#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ar[1001];
bool visited[1001];
bool removed[1001];

void init() {
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        ar[x].push_back(y);
        ar[y].push_back(x);
    }
}

void dfs(int u) {
    visited[u] = true;
    for (auto x : ar[u]) {
        if (!visited[x] && !removed[x]) {
            dfs(x);
        }
    }
}

int connected() {
    int ans = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && !removed[i]) {
            ++ans;
            dfs(i);
        }
    }

    return ans > 1 ? 0 : 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        
        for (int i = 0; i <= 1000; i++) {
            ar[i].clear();
            removed[i] = false;
        }
        
        init();

        set<int> res;

        for (int i = 1; i <= n; i++) {
            removed[i] = true;

            if (!connected()) {
                res.insert(i);
            }

            removed[i] = false;
        }

        cout << res.size() << endl;
        for (auto x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}
