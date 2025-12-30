#include<bits/stdc++.h>
using namespace std;
vector<char> ar(25);
int n;
void in(){
    for(int i=1;i<=n;i++) cout<<ar[i];
    cout<<" ";
}
void quaylui(int i){
    for(char j='A';j<='B';j++){
        ar[i]=j;
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
        cout<<endl;
        ar.clear();
    }
    return 0;
}