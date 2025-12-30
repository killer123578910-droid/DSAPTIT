#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    string low1, high1,low2,high2;
    for(int i=0;i<a.size();i++){
        if(a[i]=='5'){
            low1[i]=a[i];
            high1[i]='6';
        }else if(a[i]=='6'){
            low1[i]='5';
            high1[i]=a[i];
        }else{
            low1[i]=a[i];
            high1[i]=a[i];
        }
    }for(int i=0;i<b.size();i++){
        if(b[i]=='5'){
            low2[i]=b[i];
            high2[i]='6';
        }else if(b[i]=='6'){
            low2[i]='5';
            high2[i]=b[i];
        }else{
            low2[i]=b[i];
            high2[i]=b[i];
        }
    }
    long long l1=stoll(low1);
    long long h1=stoll(high1);
    long long l2=stoll(low2);
    long long h2=stoll(high2);
    cout<<l1+l2<<" "<<h1+h2;
    return 0;
}