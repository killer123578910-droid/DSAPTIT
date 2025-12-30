#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ar[5000];
bool visited[5000];
int parent1[5000];
void init()
{
    for (int i = 0; i < 5000; i++)
    {
        ar[i].clear();
    }
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ar[x].push_back(y);
        ar[y].push_back(x);
    }
}
void dfs(int u)
{
    visited[u] = true;
    for (auto x : ar[u])
    {
        if (!visited[x])
        {
            visited[x] = true;
            parent1[x] = u;
            dfs(x);
        }
    }
}
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto x : ar[v])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
                parent1[x] = v;
            }
        }
    }
}
void path(int u)
{   
    int n=u;
    memset(visited,false,sizeof(visited));
    memset(parent1,0,sizeof(visited));
    dfs(1);
    if(!visited[n]){
        cout<<-1<<endl;
    }else{
        vector<int> path;
        while(n!=1){
            path.push_back(n);
            n=parent1[n];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        for(auto x:path) cout<<x<<" ";
        cout<<endl;
    }
    memset(visited, false, sizeof(visited));
    memset(parent1, 0, sizeof(visited));
    bfs(u);
    if (!visited[1])
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> path;
        int i=1;
        while (i != u)
        {
            path.push_back(i);
            i = parent1[i];
        }
        path.push_back(u);
        reverse(path.begin(),path.end());
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }
}
int main()
{
    init();
    for (int i = 2; i <= n; i++)
    {   
        path(i);
    }
    return 0;
}