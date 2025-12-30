#include<bits/stdc++.h>
using namespace std;
pair<int,int> en;
map<char,int> conv;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={-1,-2,-2,-1,1,2,2,1};
void init(){
    string s(8,'?');
    iota(s.begin(),s.end(),'a');
    int cnt=1;
    for(char x:s){
        conv[x]=cnt++;
    }

}
void bfs(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    vector<vector<int>> dist(9,vector<int>(9,-1));
    dist[i][j]=0;
    while(!q.empty()){
        auto o=q.front();q.pop();
        int x=o.first;
        int y=o.second;
        if(x==en.first&&y==en.second){
            cout<<dist[x][y]<<endl;
            return;
        }
        for(int k=0;k<8;k++){
            int newx=x+dx[k];
            int newy=y+dy[k];
            if(newx<1||newy<1||newy>8||newx>8||dist[newx][newy]!=-1) continue;
            q.push({newx,newy});
            dist[newx][newy]=dist[x][y]+1;
        }
    }
}
int main(){
    init();
    int t;cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int st1=conv[s1[0]];
        int st2=s1[1]-'0';
        en.first=conv[s2[0]];
        en.second=s2[1]-'0';
        bfs(st1,st2);
    }
    return 0;
}