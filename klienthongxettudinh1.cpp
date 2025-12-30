#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n>> m;
    vector <vector<int>> dvi(n+1);
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        dvi[u].push_back(v);
        dvi[v].push_back(u);
    }
    vector<bool> daxet(n+1, false);

    stack<int> st;
    st.push(1);
    daxet[1] = true;
    while(!st.empty()){
        int u = st.top(); st.pop();
        for ( int v : dvi[u]){
            if (!daxet[v]){
                daxet[v] = true;
                st.push(v);
            }
        }
    }
    vector<int>kqua;
    for (int i=1; i<=n; i++){
        if(!daxet[i]) kqua.push_back(i);
    }
    if (kqua.empty()){
        cout << 0;
    } else {
        sort(kqua.begin(), kqua.end());
        for (int x: kqua){
            cout << x << endl;
        }
    }
}