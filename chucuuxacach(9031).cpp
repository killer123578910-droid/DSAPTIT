#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
map<tuple<int,int,int,int>,bool> wall;
vector<vector<int>> ar(101,vector<int>(101));
vector<vector<bool>> b(101,vector<bool>(101,false));
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool canmove(int a,int e,int c,int d){
    if(c<1||c>n||d<1||d>n) return false;
    if(wall[{a,e,c,d}]) return false;
    if(b[c][d]) return false;
    return true;
}
void dfs(int i,int j){
    b[i][j]=true;
    cnt+=ar[i][j];
    for(int k=0;k<4;k++){
        if(canmove(i,j,i+dx[k],j+dy[k])){
            dfs(i+dx[k],j+dy[k]);
        }
    }
}
int main(){
    cin>>n>>k>>m;
    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        wall[{a,b,c,d}]=true;
        wall[{c,d,a,b}]=true;
    }
    for(int i=1;i<=k;i++){
            int x,y;
            cin>>x>>y;
            ar[x][y]=1;
    }
    int sum=0;
    vector<int> v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!b[i][j]){
                cnt=0;
                dfs(i,j);
                v.push_back(cnt);
            }
        }
    }
    for(auto x:v) sum+=x;
    int ans=sum*(sum-1)/2;
    for(auto x:v) ans-=(x*(x-1)/2);
    cout<<ans<<endl;


    return 0;
}