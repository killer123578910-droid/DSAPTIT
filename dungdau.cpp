#include<bits/stdc++.h>
using namespace std;
vector<string> ar(25);
int a[25];
int n;
string m;
int b[25];

void in(){
    if(ar[a[1]]==m){
        for(int i=1;i<=n;i++){
            cout<<ar[a[i]]<<" ";
        }
        cout<<endl;
    }
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
    memset(b,0,sizeof(b));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    cin>>m;
    sort(ar.begin()+1,ar.begin()+n+1);
    quaylui(1);
    return 0;

}