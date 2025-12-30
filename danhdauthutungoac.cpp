#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        stack<int> st;
        int j=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='('){
                j++;
                st.push(j);
                cout<<st.top()<<" ";
            }else if(s[i]==')'){
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}