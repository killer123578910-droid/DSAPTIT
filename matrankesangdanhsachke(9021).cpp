#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    int n=t;
    cin.ignore();
    vector<vector<int>> ar(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           if(ar[i][j]==1){
                cout<<j<<" ";
           }
        }
        cout<<endl;
    }
    return 0;
}