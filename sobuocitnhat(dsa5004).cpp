#include<bits/stdc++.h>
using namespace std;
void tesecase(){
    int n;
    cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;i++) cin>>ar[i];
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(ar[i]>=ar[j]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    }
    cout<<n-*max_element(dp.begin(),dp.end())<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        tesecase();
    }
    return 0;
}