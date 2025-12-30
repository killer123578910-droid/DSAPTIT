#include <bits/stdc++.h>
using namespace std;
int n, m, u,k;
vector<int> ar[1005];
vector<bool> vi;
vector<int> parent(1005);
void dfs(int u)
{
    vi[u]=true;
    for(auto x: ar[u]){
        if(!vi[x]){
            dfs(x);
            parent[x]=u;
        }
    }
}
void tracing(int u,int k){
    dfs(u);
    vector<int> res;
    if(!vi[k]){
        cout<<-1;
    }else{
        int temp=k;
        while(temp!=u){
            res.push_back(temp);
            temp=parent[temp];
        }
        res.push_back(u);
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    }

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> u>>k;
        for (int i = 1; i <= 1004; i++)
            ar[i].clear();
        vi.assign(n + 1, false);
        parent.assign(n+1,-1);
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            ar[x].push_back(y);
        }
        tracing(u,k);
        cout << endl;
    }
    return 0;
}