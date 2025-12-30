#include<bits/stdc++.h>
using namespace std;
vector<long long> len(51);
void init(){
    len[1]=1;
    for(int i=2;i<=50;i++){
        len[i]=len[i-1]*2+1;
    }
}
long long getint(int n,long long k,long long mid,long long lenk){
    if(lenk==1) return 1;
    if(mid==k) return n;
    else{
        if(k>mid)
            return getint(n-1,k-mid,(((lenk-1)/2)+1)/2,(lenk-1)/2);
            if(k<mid){
                return getint(n-1,k,(((lenk-1)/2)+1)/2,(lenk-1)/2);
            }
    }   
}
int main(){
    int t;
    cin>>t;
    init();
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        long long lenk=len[n];
        long long mid=(lenk+1)/2;
        cout<<getint(n,k,mid,lenk)<<endl;
    }
    return 0;
}