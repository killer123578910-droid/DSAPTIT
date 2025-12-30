#include<bits/stdc++.h>
using namespace std;
//im gay. 
int main(){
    long long t;cin>>t;
    while(t--){
        long long n,k;cin>>n>>k;
        vector<int> ar(n);
        for(auto &x:ar) cin>>x;
        sort(ar.begin(),ar.end());
        //tim cap(i,j) sao cho ar[j]-ar[i]<k;
        //ar[j]<k+a[i]
        //v>=k
        //v-
        long long cont=0;
        for(long long i=0;i<n;i++){
            long long target=k+ar[i];
            auto v=lower_bound(ar.begin()+i+1,ar.end(),target);
            cont+=(v-ar.begin()-i-1);


        }
        cout<<cont<<endl;
    }
    return 0;
}