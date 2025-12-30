#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> ar[m];
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            ar[x].push_back(y);
        }
        for(int i=1;i<=n;i++){
            cout<<i<<": ";
            for(auto x:ar[i]){
                cout<<x<<" ";
            }
            cout<<endl; 
        }
    }   
    return 0;
}