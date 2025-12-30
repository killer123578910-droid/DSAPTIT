#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> ar[1001];
vector<bool> b(1005);
vector<int> p(101);
vector<int> cnt(1001,0);
void dfs(int u){
    b[u]=true;
    cnt[u]++;
    for(auto x:ar[u]){
        if(!b[x]){
            dfs(x);
        }
    }
}

int main(){
    cin>>k>>n>>m;
    for(int i=0;i<k;i++){
        cin>>p[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        ar[y].push_back(x);
    }
    int ans=0;
    for(int i=0;i<k;i++){
        fill(b.begin(),b.end(),false);
        dfs(p[i]);
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==k) ans++;
    }
    cout<<ans<<endl;

    return 0;
}