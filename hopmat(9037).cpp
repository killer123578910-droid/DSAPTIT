#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> ar[1001];
vector<bool> b(1001);
long long p[101];
void dfs(int u){
    b[u]=true;
    for(auto x:ar[u]){
        if(!b[x]){
            dfs(x);
        }
    }
}
bool isValid(){
    for(int i=0;i<k;i++){
        if(!b[p[i]]) return false;
    }
    return true;
}
int main(){
    cin>>k>>n>>m;
    for(int i=0;i<k;i++){
        cin>>p[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        ar[x].push_back(y);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        fill(b.begin(), b.end(), false);
        dfs(i);
        if(isValid()) ans++;
    }
    cout<<ans<<endl;
    return 0;
}