#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=0;
            for(int j=1;j<=3;j++){
                if(i-j>=0){
                    dp[i]=dp[i]+dp[i-j];
                }
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}