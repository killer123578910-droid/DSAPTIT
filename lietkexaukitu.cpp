#include<bits/stdc++.h>
using namespace std;
char c;
char s[26];
int k;
void in(){
    for(int i=0;i<k-1;i++){
        if(s[i]>s[i+1]){
           return;
        }
    }
    for(int i=0;i<k;i++) cout<<s[i];
    cout<<endl;
}
void quaylui(int i){
    for(char j='A';j<=c;j++){
        s[i]=j;
        if(i==k-1) in();
        else quaylui(i+1);
    }
}
int main(){
    cin>>c>>k;
    quaylui(0);
    return 0;
}