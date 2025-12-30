#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    stack<int> st;
    while(q--){
        string s;
        cin>>s;
        int n;
        if(s=="PUSH"){
            cin>>n;
            st.push(n);
        }
        else if(s=="POP"){
            if(!st.empty()){
                st.pop();
            }
        }else if(s=="PRINT"){
            if(!st.empty()){
                cout<<st.top()<<endl;
            }else{
                cout<<"NONE"<<endl;
            }
        }
    }
    return 0;
}