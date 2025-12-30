#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,s;cin>>n>>s;
        vector<int> a1(n);
        for(int i=0;i<n;i++) cin>>a1[i];
        vector<bool> dp(s,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=s;j>=a1[i];j--){
                if(!dp[j]&&dp[j-a1[i]]){
                    dp[j]=true;
                }
            }
        }
        cout<<dp[s]<<endl;
    }
    return 0;
}