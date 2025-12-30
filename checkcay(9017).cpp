#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> ar(1005);
vector<bool> b(1005);
void dfs(int u){
    b[u]=true;
    for(auto v:ar[u]){
        if(!b[v])
        dfs(v);
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        m=n-1;
        for(int i=0;i<=n;i++){
            ar[i].clear();
            b[i]=false;
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        int cc=0;
        int flag=1;
        for(int i=1;i<=n;i++){
            if(!b[i]){
                cc++;
                dfs(i);
            }
            if(cc>1){
                flag=0;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}