#include<bits/stdc++.h>
using namespace std;
int ar[25],n,m,b[100];
void in(){
    int sum=0;
    for(int i=1;i<n;i++) sum+=(ar[i]-ar[i+1]);
    if(sum>0){
    for(int i=1;i<=n;i++) {
        cout<<ar[i]<<" ";
        }
        cout<<endl;
    }
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
    cin>>n;
    quaylui(1);
}