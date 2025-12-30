#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> ar(n);
        for(auto &x:ar) cin>>x;
        sort(ar.begin(),ar.end());
        int j=n-1;
        while(k--){
            cout<<ar[j--]<<" ";
        }
        cout<<endl;
    }
    return 0;
}