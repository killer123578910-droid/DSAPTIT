#include<bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> ar[1001];
bool visited[1001];
void dfs(int u){
    visited[u]=true;
    cout<<u<<" ";
    for(auto x:ar[u]){
        if(!visited[x]){
            dfs(x);
        }
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int u;
        cin>>n>>m>>u;
        int x,y;
        for(int i=0;i<1001;i++){
            ar[i].clear();
        }
        memset(visited,false,sizeof(visited));
        for(int i=0;i<m;i++){
            cin>>x>>y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        cout<<"DFS("<<u<<") = ";
        dfs(u);
        cout<<endl;
    }
    return 0;
}