#include<bits/stdc++.h>
using namespace std;
vector<int> ar(25);
vector<int> b(100);
stack<string> st;
int n;
void in(){
    string s;
    for(int i=1;i<=n;i++){
        s+=to_string(ar[i]);
    }
    st.push(s);
}
void quaylui(int i){
    for(int j=1;j<=n;j++){
        if(b[j]==0){
            ar[i]=j;
            b[j]=1;
            if(i==n) in();
            else quaylui(i+1);
            b[j]=0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        quaylui(1);
        string s1;
        while(!st.empty()){
            s1=st.top();
            cout<<s1<<" ";
            st.pop();
        }
        ar.clear();
        b.clear();
        cout<<endl;
    }
    return 0;
}