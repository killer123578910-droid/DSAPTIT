#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,pair<int,int>> cap;
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        cap.clear();
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            cap[x].first++;
            cap[y].second++;
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            if(cap[i].first!=cap[i].second){
                flag=0;
                break;
            }
        }
        cout<<(flag?"1":"0")<<endl;
    }
    return 0;
}