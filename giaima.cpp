#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int n;
        cin>>s;
        n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=s[0]!='0'?1:0;
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            if(s.substr(i-2,2)>="10"&&s.substr(i-2,2)<="26"){
                dp[i]+=dp[i-2];
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}