#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<char>> ar(101,vector<char>(101));
vector<vector<bool>> b(101,vector<bool>(101,false));
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,-1,-1,-1,0,1,1,1};
bool canmove(int u,int v){
    if(u<0||u>n-1||v<0||v>m-1) return false;
    if(b[u][v]||ar[u][v]!='W') return false;
    return true;
}
void dfs(int u,int v){  
    b[u][v]=true;
    for(int i=0;i<8;i++){
        if(canmove(u+dx[i],v+dy[i])){
            dfs(u+dx[i],v+dy[i]);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ar[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!b[i][j]&&ar[i][j]=='W'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}