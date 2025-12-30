#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        map<int,bool> b;
        long long x;
        for(long long i=0;i<n;i++){
            cin>>x;
            while(x>0){
                b[x%10]=true;
                x/=10;
            }
        }
        for(auto x:b){
            if(x.second){
                cout<<x.first<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}