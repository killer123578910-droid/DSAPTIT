#include<bits/stdc++.h>
using namespace std;
int n;int k;
char st[16];
string s="HA";
set<string> str;
void in(){
    int flag=1;
    for(int i=1;i<=n;i++){
        if(st[i]=='H'&&st[i+1]=='H'){
            flag=0;
            break;
        }
    }
        if(st[1]=='A') flag=0;
        else if(st[n]=='H') flag=0;
    if(flag==1){
        string temp;
        for(int i=1;i<=n;i++) temp+=st[i];
        str.insert(temp);
    }
}
void quaylui(int i){
    for(auto x:s){
        st[i]=x;
        if(i==n) in();
        else quaylui(i+1);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        quaylui(1);
        for(auto x:str) cout<<x<<endl;
        str.clear();
    }
    return 0;
}
