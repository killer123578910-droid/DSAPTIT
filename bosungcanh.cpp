#include<bits/stdc++.h>
using namespace std;
vector<int> ar[100001]; 
bool vist[100011];
int n,m;
int dem=0;
void init(){
    for(int i=0;i<1001;i++){
        ar[i].clear();
    }
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        ar[x].push_back(y);
        ar[y].push_back(x);
    }
}
void dfs(int u){
    vist[u]=true;
    dem++;
    for(auto x: ar[u]){
        if(!vist[x]){
            dfs(x);
        }
    }
}
int thanhphanlonnht(){
    dem=0;
    int maxdem=0;
    for(int i=2;i<=n;i++){
        if(!vist[i]){
            dem=0;
            dfs(i);
            maxdem=max(maxdem,dem);
        }
    }
    return maxdem;
}
int main(){
    init();
    dfs(1);
    int dem1=dem;
    int maxdem=dem1+thanhphanlonnht();
    cout<<maxdem;
    
}