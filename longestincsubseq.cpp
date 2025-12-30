#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n,1);
    vector<int> ar(n);
    for(int i=0;i<n;i++) cin>>ar[i];
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(ar[i]<ar[j]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}