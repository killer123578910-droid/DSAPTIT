#include<bits/stdc++.h>
using namespace std;
int mybinary(vector<int> ar,int k,int start, int end){
    if(start>end) return 0;
    int mid=(start+end)/2;
    if(ar[mid]==k){
        return mid+1;
    }
    if(ar[mid]<k){
        return mybinary(ar,k,mid+1,end);
    }else{
        return mybinary(ar,k,start,mid-1);
    }
}

void testcase(){
    int n,k;
    cin>>n>>k;
    vector<int> ar(n);
    for(int i=0;i<n;i++) cin>>ar[i];
    int kq=mybinary(ar,k,0,n-1);
    if(kq!=0) cout<<kq<<endl;
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        testcase();
    }
    return 0;
}