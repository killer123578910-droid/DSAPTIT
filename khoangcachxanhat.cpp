#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int>> ar(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            ar[i]={i,x};
        }
        sort(ar.begin(),ar.end(),cmp);
        int ans=-1, minn=ar[0].first,k=ar[0].second;
        for(int i=1;i<n;i++){
            if(ar[i].second>k){
                ans=max(ans,(ar[i].first-minn));
            }if(ar[i].first<minn){
                minn=ar[i].first;
                k=ar[i].second;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}