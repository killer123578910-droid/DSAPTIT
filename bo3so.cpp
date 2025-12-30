#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<int> ar(n);
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
      long long count=0;
        sort(ar.begin(),ar.end());
        for(int i=0;i<n-2;i++){
            long long target=k-ar[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                if(ar[l]+ar[r]<target){
                    count+=(r-l);
                    l++;
                }else{
                    r--;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}