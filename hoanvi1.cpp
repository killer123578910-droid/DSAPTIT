#include<bits/stdc++.h>
using namespace std;
int n;
int ar[25];
int ar1[25];
int b[100];

void in(){
    for(int i=1;i<=n;i++){
        cout<<ar1[ar[i]]<<" ";
    }
    cout<<endl;

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
    for(int i=1;i<=n;i++){
        cin>>ar1[i];
    }
    sort(ar1+1,ar1+n+1);
    quaylui(1);
    return 0;
}