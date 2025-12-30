#include<bits/stdc++.h>
using namespace std;
int ar[100000];

void thuattoansinh(int n){
    int i=n;
    while(i>=0&&ar[i]==0){
        ar[i]=1;
        i--;
    }
    if(i==0){
        for(int i=1;i<=n;i++) ar[i]=1;
    }else{
        ar[i]=0;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int flag=1;
        string s;
        cin>>s;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            ar[i+1]=s[i]-'0';
        }
        thuattoansinh(n);
        for(int i=1;i<=n;i++){
            cout<<ar[i];
        }
        cout<<endl;
    }
}