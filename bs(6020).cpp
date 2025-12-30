#include<bits/stdc++.h>
using namespace std;
int bs(vector<int> &ar,int l,int r,int x){
    if(l<=r){
    int mid=l+(r-l)/2;
    if(ar[mid]==x) return 1;
    if(ar[mid]>x) return bs(ar,l,mid-1,x);
    if(ar[mid]<x) return bs(ar,mid+1,r,x);
    }else{
        return -1;
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> ar(n);
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        cout<<bs(ar,0,n-1,x)<<endl;
        
    }
    return 0;
}