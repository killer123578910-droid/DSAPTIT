#include<bits/stdc++.h>
using namespace std;
void testcase(){
    int n,s;
    cin>>n>>s;
    vector<int> ar(n);
    for(int &i: ar) cin>>i;
    vector<bool> dp(s,false);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=s;j>=ar[i];j--){
            if(dp[j]==false&&dp[j-ar[i]]==true){
                dp[j]=true;
            }
        }
    }
    cout<<(dp[s]==true?"YES":"NO")<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        testcase();
    }
    return 0;
}