#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> dp(n,1);
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(s[i]<=s[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}