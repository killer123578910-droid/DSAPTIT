#include<bits/stdc++.h>
using namespace std;
int ar[100];
int a[100];
int n=12;
int k=3;
vector<long long> postfix;
void in(){
    long long sum=0;
    for(int i=1;i<=k;i++) sum+=a[ar[i]];
    postfix.push_back(sum);
}
void quaylui(int i){
    for(int j=ar[i-1]+1;j<=n-k+i;j++){
        ar[i]=j;
        if(i==k) in();
        else quaylui(i+1);
    }
}
int main(){
    for(int i=1;i<=12;i++){
        cin>>a[i];
    }
    quaylui(1);
    sort(postfix.begin(),postfix.end());
    int mindis=INT_MAX;
    int curdis;
    for(int i=0;i<postfix.size()-1;i++){
        curdis=postfix[i+1]-postfix[i];
        mindis=min(curdis,mindis);
    }
    cout<<mindis;
    return 0;
}