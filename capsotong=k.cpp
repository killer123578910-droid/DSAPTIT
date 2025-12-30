#include<bits/stdc++.h>
using namespace std;
void merger(vector<long long> &ar,long long l,long long mid,long long r){
    long long n1=mid-l+1;
    long long n2=r-mid;
    vector<long long> l1(n1),l2(n2);
    for(long long i=0;i<n1;i++) l1[i]=ar[l+i];
    for(long long i=0;i<n2;i++) l2[i]=ar[i+mid+1];
    long long i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(l1[i]<=l2[j]){
            ar[k++]=l1[i++];
        }else if(l1[i]>l2[j]){
            ar[k++]=l2[j++];
        }
    }
    while(i<n1) ar[k++]=l1[i++];
    while(j<n2) ar[k++]=l2[j++];

}
void mymerge(vector<long long> &ar,long long l,long long r){
    if(l<r){
    long long mid=l+(r-l)/2;
    mymerge(ar,l,mid);
    mymerge(ar,mid+1,r);
    merger(ar,l,mid,r);
    }
}
int main(){
    long long t;cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long> ar(n);
        for(long long i=0;i<n;i++){
            cin>>ar[i];
        }
        mymerge(ar,0,n-1);
        long long count=0;
        for(long long i=0;i<n;i++){
            long long curcount=0;
            long long target=k-ar[i];
            auto it1 = lower_bound(ar.begin()+i+1, ar.end(), target);
            auto it2 = upper_bound(ar.begin()+i+1, ar.end(), target);
            count+=(it2-it1);
        }
        cout<<count<<endl;
    }
    return 0;
}