#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> ar(n);
    for(int i=0;i<n;i++) cin >> ar[i];
    vector<long long> dp=ar;
    long long maxA=*max_element(ar.begin(),ar.end());
    int res=0;
    int cur=0;
    for(int i=0;i<n;i++){
        if(ar[i]==maxA) cur++;
        else cur=0;
         res=max(cur,res);
    }
    cout<<res;
   
    return 0;
}