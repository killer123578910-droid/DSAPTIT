#include<bits/stdc++.h>
using namespace std;
const int modd=1e9+7;
long long f[2][2];
long long d[2][2];
void init(){
    f[0][0]=1;
    f[0][1]=1;
    f[1][0]=1;
    f[1][1]=0;
    d[0][0] = d[0][1] = d[1][0] = 1; d[1][1] = 0;
}
void multi(long long a[2][2],long long b[2][2]){
    long long x=((a[0][0]*b[0][0])%modd+(a[0][1]*b[1][0])%modd)%modd;
    long long y=((a[0][0]*b[0][1])%modd+(a[0][1]*b[1][1])%modd)%modd;
    long long z=((a[1][0]*b[0][0])%modd+(a[1][1]*b[1][0])%modd)%modd;
    long long l=((a[1][0]*b[0][1])%modd+(a[1][1]*b[1][1])%modd)%modd;
    f[0][0]=x;
    f[0][1]=y;
    f[1][0]=z;
    f[1][1]=l;
}
void expo(long long a[2][2],int n){
    if(n<=1) return;
    expo(a,n/2);
    multi(a,a);
    if(n%2==1) multi(a,d);
}
int main(){
    int t;cin>>t;
    while(t--){
        init();
        long long n;
        cin>>n;
        expo(f,n);
        cout<<f[0][1]<<endl;
    }
    return 0;
}