#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> ar(n);
        for(auto &x:ar) cin>>x;
        sort(ar.begin(),ar.end());
        auto it1= lower_bound(ar.begin(),ar.end(),k);
        auto it2= upper_bound(ar.begin(),ar.end(),k);
        if(it2-it1!=0){
            cout<<it2-it1<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}