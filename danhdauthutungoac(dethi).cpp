#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        stack<int> st;
        int counter=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(counter);
                cout<<counter<<" ";
                counter++;
                
            }else if(s[i]==')'){
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        cout<<endl;
    }
}