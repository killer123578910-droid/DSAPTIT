#include<bits/stdc++.h>
using namespace std;
vector<int> ar[1001];
int n,m,u;
bool visited[1001];
int parent[1001];
void init(){
    for(int i=1;i<=n;i++){
        ar[i].clear();
    }
    cin>>n>>m>>u;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        ar[x].push_back(y);
        ar[y].push_back(x);
    }
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();q.pop();
        for(int x:ar[v]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
                parent[x]=v;
            }
        }
    }
}
void path(int i){
    memset(parent,0,sizeof(parent));
    memset(visited,false,sizeof(visited));
    bfs(u);
    if(!visited[i]){
        cout<<"No path"<<endl;
        return;
    }else{
        vector<int> path;
        while(i!=u){
            path.push_back(i);
            i=parent[i];
        }
        path.push_back(u);
        reverse(path.begin(),path.end());
        for(auto x:path){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        init();
        for(int i=1;i<=n;i++){
            if(i==u) continue;
            else{
                path(i);
            }
        }
    }
}