#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>s;
        stack<string> st;
        n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
                string x=st.top();st.pop();
                string y=st.top();st.pop();
                string z=s[i]+y+x;
                st.push(z);
            }else{
                st.push(string(1,s[i]));
            }
        }
        cout<<st.top()<<endl;
    }
    return 0;
}