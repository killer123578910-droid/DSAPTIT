#include<bits/stdc++.h>
using namespace std;
vector<int> ar[100006];
bool b[100006];
int maxcap=0;
void dfs(int i,int cap){
    maxcap=max(maxcap,cap);
    b[i]=true;
    for(auto x:ar[i]){
        if(!b[x]){
            dfs(x,cap+1);
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<100006;i++) ar[i].clear();
        fill(b, b + 100006, false);
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            ar[x].push_back(y);
        }
        maxcap=0;
        dfs(1,0);
        cout<<maxcap<<endl;
    }
}