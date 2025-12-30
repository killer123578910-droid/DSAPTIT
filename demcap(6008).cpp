#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ar[5]={};
        vector<int> x(n),y(m);
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<m;i++){
            cin>>y[i];
            if(y[i]<5){
                ar[y[i]]++;
            }
        }
        sort(y.begin(),y.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(x[i]==0) continue;
            else if(x[i]==1) ans+=ar[0];
            else{
            int idx=upper_bound(y.begin(),y.end(),x[i])-y.begin();
            int curans=m-idx;
            curans+=(ar[0]+ar[1]);
            if(x[i]==2){
                curans-=(ar[3]+ar[4]);
            }
            if(x[i]==3){
                curans+=ar[2];
            }
            ans+=curans;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}