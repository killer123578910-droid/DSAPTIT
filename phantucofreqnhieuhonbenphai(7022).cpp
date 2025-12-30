#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ar(n);
        map<int,int> freq;
        for(int i=0;i<n;i++){
            cin>>ar[i];
            freq[ar[i]]++;
        }
        vector<int> te(n);
        for(int i=0;i<n;i++){
            te[i]=freq[ar[i]];
        }
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&te[i]>=te[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=ar[st.top()];
            st.push(i);
        }
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }
    return 0;

}