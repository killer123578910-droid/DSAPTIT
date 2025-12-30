#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt=0;
int id[1005];
int low[1005];
vector<int> ar[1005];
vector<int> b(1005);
set<int> dinh;
void dfs(int i,int p){
    id[i]=low[i]=++cnt;
    int node=(p!=0);
    for(auto x:ar[i]){
        if(x==p) continue;
        if(id[x]) low[i]=min(low[i],id[x]);
        else{
            dfs(x,i);
            low[i]=min(low[x],low[i]);
            if(low[x]>=id[i]) node++;
        }
    }
    if(node>=2) dinh.insert(i);
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            ar[i].clear();
            b[i]=false;
            id[i]=0;low[i]=0;
        }
        dinh.clear();
        cnt=0;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            if(!id[i]){
                dfs(i,0);
            }
        }
        for(auto x:dinh) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}