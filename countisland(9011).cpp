#include<bits/stdc++.h>
using namespace std;
int n,m;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,-1,-1,-1,0,1,1,1};
void dfs(int i,int j, vector<vector<int>> &ar,vector<vector<bool>> &b){
    b[i][j]=true;
    for(int k=0;k<8;k++){
        if(i+dx[k]>=0&&j+dy[k]>=0&&i+dx[k]<n&&j+dy[k]<m&&ar[i+dx[k]][j+dy[k]]&&!b[i+dx[k]][j+dy[k]]){
            dfs(i+dx[k],j+dy[k],ar,b);
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        int tplt=0;
        vector<vector<int>> ar(n,vector<int>(m));
        vector<vector<bool>> b(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>ar[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j]==1&&!b[i][j]){
                    dfs(i,j,ar,b);
                    tplt++;
                }
            }
        }
        cout<<tplt<<endl;
    }
    return 0;
}