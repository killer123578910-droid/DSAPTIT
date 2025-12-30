#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }else{
                string tp="";
                while(!st.empty()&&st.top()!='('){
                    tp=st.top()+tp;
                    st.pop();
                }
                st.pop();
                if(!st.empty()&&st.top()=='-'){
                    for(auto x:tp){
                        if(x=='+') x='-';
                        else if(x=='-') x='+';
                        st.push(x);
                    }
                }else{
                    for(auto x:tp){
                        st.push(x);
                    }
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}