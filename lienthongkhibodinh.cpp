#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ar[100000];
bool visited[100000];
bool removed[100000];

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

    return ans;
}

int main() {
   
        cin >> n >> m;
        init();
        for (int i = 1; i <= n; i++) {
            removed[i] = true;
            cout<<connected()<<endl;
            removed[i] = false;
        }
    return 0;
}
