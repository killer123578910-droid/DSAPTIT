#include<bits/stdc++.h>
using namespace std;
void testcase(){
    int n,w;
    cin>>n>>w;
    int val[n];
    int wt[n];
    for(int i=1;i<=n;i++){
        cin>>wt[i];
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(wt[i]<=j){
                dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        testcase();
    }
    return 0;
}