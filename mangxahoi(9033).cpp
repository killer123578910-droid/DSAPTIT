#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> ar(100006);
vector<bool> b(100006,false);
void bfs(int u){
    queue<int> q;
    b[u]=true;
    q.push(u);
    while(!q.empty()){
        int t=q.front();q.pop();
        for(int x:ar[t]){
            if(!b[x]){
                b[x]=true;
                q.push(x);
            }
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
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        int flag=1;
        bfs(1);
        for(int i=2;i<=n;i++){
            if(!b[i]){
                flag=0;
                break;
            }
        }
        cout<<(flag==1?"YES":"NO")<<endl;
    }
    return 0;
}