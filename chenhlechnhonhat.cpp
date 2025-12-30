#include<bits/stdc++.h>
using namespace std;
//im gay. 
int main(){
    long long t;cin>>t;
    while(t--){
        long long n,k;cin>>n;
        vector<long long> ar(n);
        for(auto &x:ar) cin>>x;
        sort(ar.begin(),ar.end());
        //tim cap(i,j) sao cho ar[j]-ar[i]<k;
        //ar[j]<k+a[i]
        //v>=k
        //v-
        long long mingap=INT_MAX;
        for(long long i=0;i<n-1;i++){
            mingap=min(mingap,ar[i+1]-ar[i]);
        }
        cout<<mingap<<endl;
    }
    return 0;
}