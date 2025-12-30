#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,p;
    cin>>n>>p;
    vector<long long> d;
    for(int i=1;i<=sqrt(p);i++){
        if(p%i==0){
            d.push_back(i);
        }
        if(i!=p/i){
            d.push_back(p/i);
        }
    }
    long long maxglo=1;
    for(int i=0;i<d.size();i++){
        long long k=d[i];
        long long div=pow(k,n);
        if(p%div==0){
         maxglo=max(maxglo,k);
        }
    }
     cout<<maxglo<<endl;
    return 0;
}