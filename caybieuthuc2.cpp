#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> s;
        string temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            s.push_back(temp);
        }
        queue<int> st;
        for(int i=n-1;i>=0;i--){
            if(s[i]=="+"||s[i]=="-"||s[i]=="*"||s[i]=="/"){
                int x= st.front();st.pop();
                int y=st.front();st.pop();
                if(s[i]=="+"){
                    int z=x+y;
                    st.push(z);
                }if(s[i]=="-"){
                    int z=y-x;
                    st.push(z);
                }if(s[i]=="*"){
                    int z=x*y;
                    st.push(z);
                }if(s[i]=="/"){
                    int z=y/x;
                    st.push(z);
                }
            }else{
                int temp=stoi(s[i]);
                st.push(temp);
            }
        }
        cout<<st.front()<<endl;
    }
    return 0;
}