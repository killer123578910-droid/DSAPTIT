#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> ar(1005);
vector<bool> b(1005);
int flag=0;
void dfs(int u,int parent){
    b[u]=true;
    for(auto v:ar[u]){
        if(!b[v])
        dfs(v,u);
        else if(v!=parent){
            flag=1;
        }
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            ar[i].clear();
            b[i]=false;
        }
        flag=0;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        for(int i=1;i<=n;i++) if(!b[i]) dfs(i,0);
        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}