#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> ar(n),l(n),r(n);
        for(auto&x:ar) cin>>x;
        l[0]=1;
        for(int i=1;i<n;i++){
            if(ar[i]>ar[i-1]){
                l[i]=l[i-1]+1;
            }else{
                l[i]=1;
            }
        }
        r[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(ar[i]>ar[i+1]){
                r[i]=r[i+1]+1;
            }
            else r[i]=1;
        }
        int maxleng=1;
        for(int i=0;i<n;i++){
            maxleng=max(maxleng,r[i]+l[i]-1);
        }
        cout<<maxleng<<endl;        
    }
    return 0;
}