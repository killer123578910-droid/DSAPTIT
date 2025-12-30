#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> ar(n);
        for(int i=0;i<n;i++) cin>>ar[i];
        stack<int> st;
        vector<int> greater(n);
        greater[n-1]=-1;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&&ar[i]>=ar[st.top()]){
                st.pop();
            }
            if(st.empty()) greater[i]=-1;
            else{
                greater[i]=st.top();
            }
            st.push(i);
        }
        stack<int> st2;
        vector<int> smaller(n);
        for(int i=n-1;i>=0;i--){
            while(!st2.empty()&&ar[i]<=st2.top()) st2.pop();
            if(st2.empty()) smaller[i]=-1;
            else smaller[i]=st2.top();
            st2.push(ar[i]);
        }
        for(int i=0;i<n;i++){
            if(greater[i]!=-1){
                cout<<smaller[greater[i]]<<" ";
            }else{
                cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}