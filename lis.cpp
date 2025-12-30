#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a1(n);
        for(int i=0;i<n;i++) cin>>a1[i];
        vector<int> dp(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(a1[j]>a1[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        cout<<*max_element(dp.begin(),dp.end())<<endl;
    }
    return 0;
}