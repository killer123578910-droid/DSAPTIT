#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int stt=1;
int n;
vector<int> A(25);
vector<int> B(100);
void in(){
    //cout<<stt++<<": ";
    for(int i=1;i<=n;i++) cout<<A[i];
    cout<<" ";
}
void quaylui(int i){
    for(int j=1;j<=n;j++){
        if(B[j]==0){
            A[i]=j;
            B[j]=1;
            if(i==n) in();
            else quaylui(i+1);
            B[j]=0;

        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        quaylui(1);
        A.clear();
        B.clear();
        cout<<endl;  
    }
    

    return 0;
}
