#include<bits/stdc++.h>
using namespace std;
int n;
int ar[100];
int xuoi[20];
int nguoc[20];
int x[100];
int cont=0;
void quanhau(int i){
    for(int j=1;j<=n;j++){
        if(!ar[j]&&!xuoi[i-j+n]&&!nguoc[i+j-1]){
            x[i]=j;
            ar[j]=1;
            xuoi[i-j+n]=1;
            nguoc[i+j-1]=1;
            if(i==n) cont++;
            else{
                quanhau(i+1);
            }
            ar[j]=0;
            xuoi[i-j+n]=0;
            nguoc[i+j-1]=0;
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        quanhau(1);
        cout<<cont<<endl;
        cont=0;
    }
    return 0;    
}