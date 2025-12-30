#include<bits/stdc++.h>
using namespace std;
int cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> cv(n);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            cv[i]=make_pair(x,y);
        }
        sort(cv.begin(),cv.end(),cmp);
        int pref=cv[0].second;
        int count=1;
        for(int i=1;i<n;i++){
                if(cv[i].first>=pref){
                    count++;
                    pref=cv[i].second;
                }
        }
        cout<<count<<endl;        
    }
    return 0;
}