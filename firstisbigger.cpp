#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> ar(n);
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        stack<long long> st;
        long long res[n];
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&ar[i]>=st.top()) st.pop();
            if(st.empty()) res[i]=-1;
            else res[i]=st.top();
            st.push(ar[i]);
        }
        for(int i=0;i<n;i++) cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}