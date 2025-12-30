#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ar(n);
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            cin>>ar[i];
            dp[i]=ar[i];
        }
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i],dp[i]+dp[i-1]);
        }
        cout<<*max_element(dp.begin(),dp.end())<<endl;;
    }
    return 0;
}