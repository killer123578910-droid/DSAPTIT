#include<bits/stdc++.h>
using namespace std;
long long modd=1e9+7;
long long luythua(long long a, long long b){
    if(b==0) return 1;
    long long x=luythua(a,b/2);
    if(b%2==0){
        return (x*x)%modd;
    }else{
        return (a*((x*x)%modd))%modd;
    }
}
int main(){
    long long x,y;
    while(1){
        cin>>x>>y;
        if(x==0&&y==0) break;
        cout<<luythua(x,y)<<endl;
    }
    return 0;
}