#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1001];
bool visited[1001];
int parent[1001];
int n,m,u,v;
void init(){
    for(int i=1;i<=1001;i++){
        ar[i].clear();
    }
    memset(visited,false,sizeof(visited));
    cin>>n>>m>>u>>v;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        ar[x].push_back(y);
        //ar[y].push_back(x);
    }
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto x:ar[v]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
                parent[x]=v;
            }
        }
    }
}
void path(int u,int v){
    memset(parent,0,sizeof(parent));
    bfs(u);
    if(!visited[v]){
        cout<<-1<<endl;
        return;
    }else{
        vector<int> res;
        while(v!=u){
            res.push_back(v);
            v=parent[v];
        }
        res.push_back(v);
        reverse(res.begin(),res.end());
        for(auto x:res) cout<<x<<" ";
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        init();
        path(u,v);
    }
    return 0;

}