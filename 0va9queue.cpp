#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        queue<int> qu;
        int x=9;
        qu.push(x);
        while(x%n!=0){
            x=qu.front();qu.pop();
            int x1=x*10;qu.push(x1);
            int x2=x*10+9;qu.push(x2);
        }
        cout<<x<<endl;
    }
    return 0;
}