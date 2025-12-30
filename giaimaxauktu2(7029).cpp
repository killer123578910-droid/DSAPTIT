#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<string> st;
        stack<int> st2;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                string num="";
                while(i<s.size()&&isdigit(s[i])){
                    num+=s[i];
                    i++;
                }
                i--;
                st2.push(stoi(num));
            }else if(s[i]==']'){
                string temp="";
                while(!st.empty()&&st.top()!="["){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                int cnt=st2.top();st2.pop();
                string expand="";
                while(cnt--) expand+=temp;
                st.push(expand);
            }else{
                st.push(string(1,s[i]));
                if(s[i]=='['&&(!isdigit(s[i-1])||i==0)){
                    st2.push(1);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        while (!st2.empty())
        {
            st2.pop();
        }
        cout<<ans<<endl;
        
    }
    return 0;
}