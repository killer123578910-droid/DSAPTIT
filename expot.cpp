#include<bits/stdc++.h>
using namespace std;
const int modd=1e9+7;
long long expo(long long n, long long k){
    if(k==0) return 1;
    if(k==1) return n;
    long long x=expo(n,k/2);
    long long nh=(x*x)%modd;
    if(k%2==0) return nh;
    return (nh*n)%modd;
}

int main(){
    int t;cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        cout<<expo(n,k)<<endl;
    }
}