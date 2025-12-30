#include<bits/stdc++.h>
using namespace std;
int n;
long long value[200001];
vector<long long> ar[200001];
bool b[200001];
int dfs(int u){
    b[u]=true;
    int sz=0;
    value[u]=1;
    for(auto x:ar[u]){
        if(!b[x]){
            sz+=dfs(x);
            value[u]+=value[x];
            b[x]=true;
        }
    }
    value[u]+=sz;
    return sz+1;
}
int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        ar[x].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<value[i]<<" ";
    }
    return 0;
}