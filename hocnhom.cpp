#include<bits/stdc++.h>
using namespace std;
set<int> ar[200001];
bool visited[100001];
int n,m;
void init(){
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        ar[x].insert(y);
        ar[y].insert(x);
    }
}
void bfs(int u){
    queue<int> q;
    visited[u]=true;
    q.push(u);
    while(!q.empty()){
        int v=q.front();q.pop();
        for(auto x:ar[v]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
int sothanhphan(){
    int count=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            count++;
            bfs(i);
        }
    }
    return count;
}
int main(){
    init();
    cout<<sothanhphan()<<endl;
    return 0;
}