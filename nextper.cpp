#include<bits/stdc++.h>
using namespace std;
int ar[100000];

int flag=1; 
void thuattoansinh(int n){
    int i=n;
    while(i>=1&&ar[i]==1){
        ar[i]=0;
        i--;
    }
    if(i==0){
        flag=0;
    }else{
        ar[i]=1;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            ar[i+1]=s[i]-'0';
        }
        thuattoansinh(n);
        for(int i=1;i<=s.size();i++){
            cout<<ar[i];
        }
        cout<<endl;
    }
    return 0;
}