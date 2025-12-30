#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n; vector<int> ar(n);
        for(auto &x:ar) cin>>x;
        stack<int> st;
        vector<int> b(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&ar[st.top()]<=ar[i]) st.pop();
            if(st.empty()) b[i]=i+1;
            else b[i]=i-st.top();
            st.push(i); 
        }
        for(auto x:b) cout<<x<<" ";
        cout<<endl; 
    }   
    return 0;
}