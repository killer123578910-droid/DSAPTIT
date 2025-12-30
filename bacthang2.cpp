#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long long n,k;cin>>n>>k;
        
        vector<long long> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(j<=i){
                    dp[i]=dp[i]+dp[i-j];
                }
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}