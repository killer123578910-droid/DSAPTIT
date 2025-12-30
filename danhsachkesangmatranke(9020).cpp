#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    int n=t;
    cin.ignore();
    vector<vector<int>> ar(n+1,vector<int>(n+1,0));
    for(int i=1;i<=t;i++){
        string s;
        getline(cin,s);
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            ar[i][stoi(temp)]=1;
            ar[stoi(temp)][i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}