#include<bits/stdc++.h>
using namespace std;
int n,m;
int cc=0;
vector<vector<int>> ar(1005);
int id[1005];
int low[1005];
int cnt=0;
stack<int> st;
void dfs(int u){
    id[u]=low[u]=++cnt;
    st.push(u);
    for(auto v:ar[u]){
        if(id[v]) low[u]=min(low[u],id[v]);
        else{
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==id[u]){
        int v=0;
        cc++;
        id[u]=n+1;
        while(v!=u){
            v=st.top();
            id[v]=n+1;
            st.pop();
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            ar[i].clear();
            id[i]=0;
            low[i]=0;
        }
        cnt=0;
        cc=0;
        while(!st.empty()) st.pop();
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            ar[x].push_back(y);
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            if(!id[i]){
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