#include<bits/stdc++.h>
using namespace std;
int n,k,ar[25];
int check(int ar[]){
    for(int i=1;i<k;i++){
        if(ar[i]>ar[i+1]) return 0;
    }
    return 1;
}
void in(){
    for(int i=1;i<=k;i++) cout<<ar[i]<<" ";
    cout<<endl;
    }
void quaylui(int i,int start){
    for(int j=start;j<=n;j++){
        ar[i]=j;
        if(i==k) in();
        else quaylui(i+1,j);
    }
}
int main(){
    cin>>n>>k;
    quaylui(1,1);
    return 0;
}