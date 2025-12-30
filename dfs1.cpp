#include<bits/stdc++.h>
using namespace std;
int v,e;
vector<int> ar[1001];
vector<bool> visited(1001,false);
void dfs(int i){
    cout<<i<<" ";
    visited[i]=true;
    for(auto v:ar[i]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        int u;
        cin>>v>>e>>u;
        for(int i=1;i<1001;i++) ar[i].clear();
        fill(visited.begin(), visited.end(), false);
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            ar[x].push_back(y);
        }
        dfs(u);
        cout<<endl;
    }
    return 0;
}