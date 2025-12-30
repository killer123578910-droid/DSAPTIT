#include<bits/stdc++.h>
using namespace std;
string ar;
int a[25];
int b[100];
int n;
void in(){
    for(int i=1;i<=n;i++){
        cout<<ar[a[i]-1];
    }
    cout<<" ";
}
void quaylui(int i){
    for(int j=1;j<=n;j++){
        if(b[j]==0){
            a[i]=j;
            b[j]=1;
            if(i==n) in();
            else quaylui(i+1);
            b[j]=0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>ar;
        n=ar.size();
        memset(b,0,sizeof(b));
        quaylui(1);
        cout<<endl;
        ar.clear();
    }
    return 0;
}