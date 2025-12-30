#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        unordered_map<long long,long long> dist;
        queue<long long> q;
        dist[n]=0;
        q.push(n);
        while(!q.empty()){
            long long cu=q.front();
            q.pop();
            if(cu==2) break;
            if(!dist.count(cu-1)){
                dist[cu-1]=dist[cu]+1;
                q.push(cu-1);
            }
            for(long long i=2;i<=sqrt(cu);i++){
                if(cu%i==0){
                    if(!dist.count(max(i,cu/i))){
                        dist[max(i,cu/i)]=dist[cu]+1;
                        q.push(max(i,cu/i));
                    }
                }
            }
        }
        cout<<dist[2]+1<<endl;
    }
    return 0;
}