#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        vector<long long> a(n),b(n);
        for(auto &x:a) cin>>x;
        for(auto &x:b) cin>>x;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=(1LL*a[i]*b[n-i-1]);
        }
        cout<<sum<<endl;
    }
    return 0;
}