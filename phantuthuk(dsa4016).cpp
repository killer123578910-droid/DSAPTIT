#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &a,vector<int>&b,long long z){
    int n=a.size();
    int m=b.size();
    long long k=m+n;
    vector<int> res(k);
    int i=0;int j=0;
    int l=0;
    while(i<k){
        if(j<n&&a[j]<=b[l]){
            res[i]=a[j];
            j++;
        }else if(l<m&&a[j]>b[l]){
            res[i]=b[l];
            l++;
        }
        i++;
    }
    cout<<res[z-1]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> a(n);
        vector<int> b(m);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        solve(a,b,k);
    }
    return 0;
}