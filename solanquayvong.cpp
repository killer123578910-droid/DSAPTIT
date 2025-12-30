#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        vector<long long> ar(n);
        long long maxx=INT_MIN;
        int idx=0;
        for(int i=0;i<n;i++){
            cin>>ar[i];
            long long temp=maxx;
            maxx=max(maxx,ar[i]);
            if(maxx!=temp) idx=i; 
        }
        if(idx==n-1) cout<<0<<endl;
        else cout<<idx+1<<endl;

    }
    return 0;
}