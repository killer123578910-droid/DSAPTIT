#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ar(1005);
void bfs(int u,int v){
    unordered_map<int,int> dist;
    queue<int> q;
    dist[u]=0;
    q.push(u);
    while(!q.empty()){
        int cur=q.front();q.pop();
        if(cur==v){
            cout<<dist[v]<<endl;
            return;
        }
        for(auto x:ar[cur]){
            if(!dist.count(x)){
                q.push(x);
                dist[x]=dist[cur]+1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<=n;i++){
            ar[i].clear();
        }
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        int q;cin>>q;
        for(int i=0;i<q;i++){
            int u,v;
            cin>>u>>v;
            bfs(u,v);
        }
    }
    return 0;
}