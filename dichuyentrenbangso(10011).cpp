#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ar(501,vector<int>(501));
int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
void dijkstra(){
    priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> q;
    vector<vector<long long>> d(501,vector<long long>(501,LLONG_MAX));
    d[1][1]=ar[1][1];
    q.push({0,1,1});
    while(!q.empty()){
        tuple<long long,int,int> te=q.top();
        q.pop();
        long long kc=get<0>(te);
        int x=get<1>(te);
        int y=get<2>(te);
        if(kc>d[x][y]) continue;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx<1||newx>n||newy<1||newy>m) continue;
            if(d[newx][newy]>d[x][y]+ar[newx][newy]){
                d[newx][newy]=d[x][y]+ar[newx][newy];
                q.push({d[newx][newy],newx,newy});
            }
        }
    }
    cout<<d[n][m]<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ar[i][j];
            }
        }
        dijkstra();
    }
    return 0;
}