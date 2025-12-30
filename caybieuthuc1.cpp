#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<string> st;
        for(int i=0;i<s.size();i++){
            string temp=string(1,s[i]);
            if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
                string x1=st.top();st.pop();
                string x2=st.top();st.pop();
                string x3=x2+temp+x1;
                st.push(x3);
            }else{
                st.push(temp);
            }
        }
        cout<<st.top()<<endl;
    }
    return 0;
}