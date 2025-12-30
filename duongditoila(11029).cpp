#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ar;  
vector<bool> b;          
vector<int> parent;      
vector<vector<int>> child; 

void dfs(int i) {
    b[i] = true;
    for (auto x : ar[i]) {
        if (!b[x]) {
            dfs(x);
            parent[x] = i;
            child[i].push_back(x);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        ar.assign(n + 1, vector<int>());
        child.assign(n + 1, vector<int>());
        b.assign(n + 1, false);
        parent.assign(n + 1, 0);

        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }

        dfs(1);

        for (int i = 1; i <= n; i++) {
            if (child[i].empty()) {
                stack<int> st;
                int j = i;
                while (j != 1) {
                    st.push(j);
                    j = parent[j];
                }
                st.push(1);

                while (!st.empty()) {
                    cout << st.top() << " ";
                    st.pop();
                }
                cout << endl;
            }
        }
    }
    return 0;
}
