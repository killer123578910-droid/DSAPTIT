#include<bits/stdc++.h>
using namespace std;
int n;int k;
string aplh="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int a[18];
void in(string st){
    for(int i=1;i<k;i++){
        if(st[a[i]-1]==st[a[i+1]]-1){
            return;
        }
    }
    for(int i=1;i<=k;i++){
        cout<<st[a[i]-1];
    }
    cout<<endl;
}
void quaylui(int i,string st){
    for(int j=a[i-1]+1;j<=n-k+i;j++){
        a[i]=j;
        if(i==k) in(st);
        else quaylui(i+1,st);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string st=aplh.substr(0,n);
        quaylui(1,st);
    }
    return 0;
}
