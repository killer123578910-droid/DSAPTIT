#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ar(n);
        map<int,int> mapl;
        for(int i=0;i<n;i++){
            cin>>ar[i];
            mapl[ar[i]]++;
        }
        for(auto x: mapl){
            while(x.second>0){
                cout<<x.first<<" ";
                x.second--;
            }
        }
        cout<<endl;
    }
    return 0;
}