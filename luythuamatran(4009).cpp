#include<bits/stdc++.h>
using namespace std;
const int modd=1e9+7;
long long n;
vector<vector<long long>> f;
void init(vector<vector<long long>> ar){
    f=ar;
}
vector<vector<long long>> multi(vector<vector<long long>> a,vector<vector<long long>> b){
    vector<vector<long long>> res(n,vector<long long>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                res[i][j]=(res[i][j]+(a[i][k]*b[k][j])%modd)%modd;
            }
        }
    }
    return res;
}
vector<vector<long long>> expo(vector<vector<long long>> a,long long k){
    if(k==1) return a;
    vector<vector<long long>> res=expo(a,k/2);
    if(k%2==0){
        return multi(res,res);
    }else{
        return multi(multi(res,res),f);
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        long long k;cin>>n>>k;
        vector<vector<long long>> ar(n,vector<long long>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ar[i][j];
            }
        }
        init(ar);
        vector<vector<long long>> res=expo(ar,k);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}