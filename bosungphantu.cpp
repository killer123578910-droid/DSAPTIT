#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n;
        map<int,int> mapl;
        vector<int> ar(n);
        
        int maxm=0;
        int minm=INT_MAX;
        for(auto &x:ar){
            cin>>x;
            maxm=max(maxm,x);
            minm=min(minm,x);
            mapl[x]++;
        }
        for(int i=minm;i<=maxm;i++){
            mapl[i]++;
        } 
        int count=0;
        for(auto x:mapl){
            if(x.second==1){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}