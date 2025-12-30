#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;long long k;
        cin>>n>>k;
        vector<long long> ar(n);
        for(auto&x: ar) cin>>x;
        sort(ar.begin(),ar.end());
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long target=k-ar[i]-ar[j];
                if(binary_search(ar.begin()+j+1,ar.end(),target)){
                    flag=1;
                    break;
                }
                
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
 return 0;   
}