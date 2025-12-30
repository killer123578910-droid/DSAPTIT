#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.second==y.second){
            return x.first<y.first;
    }
    return x.second>y.second;

}
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n;
        map<int,int> mapl;
        vector<int> ar(n);
        for(auto &x:ar){
            cin>>x;
            mapl[x]++;
        }
        int i=0;
        vector<pair<int,int>> b(n);
        for(auto x:mapl){
            b[i].first=x.first;
            b[i].second=x.second;
            i++;
        }
        sort(b.begin(),b.end(),cmp);
        for(auto x:b){
            while(x.second--){
                cout<<x.first<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}