#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n1,n2;
        cin>>n1>>n2;
        vector<int> ar1(n1),ar2(n2);
        set<int> unionn;
        map<int,int> mapl;
        for(int i=0;i<n1;i++){
             cin>>ar1[i];
             unionn.insert(ar1[i]);
             mapl[ar1[i]]++;
        }
         for(int i=0;i<n2;i++){
            cin>>ar2[i];
            unionn.insert(ar2[i]);
            mapl[ar2[i]]++;
        }
        for(auto x:unionn) cout<<x<<" ";
        cout<<endl;
        for(auto x:mapl){
            if(x.second==2){
                cout<<x.first<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}