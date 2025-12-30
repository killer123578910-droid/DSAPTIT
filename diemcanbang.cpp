#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> ar(n);
         long long sumr=0;
        for(auto &x:ar) cin>>x,sumr+=x;
        long long suml=0;       
        int l=0;
        int kq=-1;
        while(l<n){
            
            suml+=ar[l];
            sumr-=ar[l];
            l++;
            sumr-=ar[l];
          
            if(suml==sumr) {
                kq=l+1;
                break;
            }
            sumr+=ar[l];
        }
        cout<<kq<<endl;
    }
    return 0;
}