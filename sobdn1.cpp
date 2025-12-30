#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        unsigned long long n;cin>>n;
        queue<unsigned long long> qu;
        unsigned long long x=1;
        unsigned long long cnt=0;
        qu.push(x);
        while(x<=n){
            x=qu.front();qu.pop();
            if(x<=n) cnt++;
            unsigned long long x1=x*10;qu.push(x1);
            unsigned long long x2=x*10+1;qu.push(x2);
        }
        cout<<cnt<<endl;
    }
    return 0;
}