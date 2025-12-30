#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> ar(n),dp(n+1);
        for(auto &x:ar) cin>>x;
        dp[0]=0;
        dp[1]=ar[0];
        dp[2]=max(ar[0],ar[1]);
        for(int i=3;i<=n;i++){
            dp[i]=max(dp[i-1],(dp[i-2]+ar[i-1]));
        }
        cout<<*max_element(dp.begin(),dp.end())<<endl;
    }
    return 0;

}