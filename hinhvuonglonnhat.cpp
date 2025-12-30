#include<bits/stdc++.h>
using namespace std;
void testcase(){
int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int dp[n+1][m+1]={};
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0) continue;
            else{
                dp[i][j]=min({
                    dp[i-1][j],
                    dp[i-1][j-1],
                    dp[i][j-1]
                })+1;
                ans=max(ans, dp[i][j]);
            }
            
        }
    }
    cout<<ans<<endl;
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        testcase();
    }
    return 0;

}