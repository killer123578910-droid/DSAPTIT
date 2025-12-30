#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> en;
vector<vector<char>> ar(101, vector<char>(101));
vector<vector<int>> dist(101, vector<int>(101));

void bfs(int sx, int sy){
    queue<pair<int,int>> q;
    dist[sx][sy] = 0;
    q.push({sx,sy});
    
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        
        if(x==en.first && y==en.second){
            cout << dist[x][y] << "\n";
            return;
        }
        
        // UP
        for(int k=x-1; k>=0 && ar[k][y] != 'X'; k--){
            if(dist[k][y] == -1){
                dist[k][y] = dist[x][y] + 1;
                q.push({k,y});
            }
        }
        // DOWN
        for(int k=x+1; k<n && ar[k][y] != 'X'; k++){
            if(dist[k][y] == -1){
                dist[k][y] = dist[x][y] + 1;
                q.push({k,y});
            }
        }
        // LEFT
        for(int k=y-1; k>=0 && ar[x][k] != 'X'; k--){
            if(dist[x][k] == -1){
                dist[x][k] = dist[x][y] + 1;
                q.push({x,k});
            }
        }
        // RIGHT
        for(int k=y+1; k<n && ar[x][k] != 'X'; k++){
            if(dist[x][k] == -1){
                dist[x][k] = dist[x][y] + 1;
                q.push({x,k});
            }
        }
    }
    
    cout << -1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> ar[i][j];

        // reset dist
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = -1;

        int sx,sy;
        cin >> sx >> sy >> en.first >> en.second;

        bfs(sx,sy);
    }
    return 0;
}
