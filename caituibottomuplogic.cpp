#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;int wt;
    cin>>n>>wt;
    int v[n];
    int w[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(wt+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=wt;j++){
            if(w[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
            }
        }
    }
    cout<<dp[n][wt];
    return 0;
}