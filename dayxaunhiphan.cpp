#include<bits/stdc++.h>
using namespace std;
vector<long long> len(93);
void init(){
    len[1]=1;
    len[2]=1;
    for(int i=3;i<93;i++){
        len[i]=len[i-2]+len[i-1];
    }
}
int getint(int n,long long k){
    if(n==1) return 0;
    if(n==2) return 1;
    if(k<=len[n-2]){
        return getint(n-2,k);
    }else{
        return getint(n-1,k-len[n-2]);
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
        cout<<getint(n,k)<<endl;
    }
    return 0;
}