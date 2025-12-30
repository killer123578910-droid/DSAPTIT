#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ar[1000];
bool visited[1000];
vector<pair<int, int>> ar1;
void init()
{
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        ar[x].push_back(y);
        ar[y].push_back(x);
        ar1.push_back(make_pair(x, y));
    }
}

void dfs(int u)
{
    visited[u] = true;
    for (auto x : ar[u])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}

int connected()
{
    int ans = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ++ans;
            dfs(i);
        }
    }

    return ans>1?1:0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i <= 1000; i++)
        {
            ar[i].clear();
            visited[i] = false;
        }
        init();
        set<pair<int,int>> res;
        for(int i=0;i<m;i++){
            string s;
            ar[ar1[i].first].erase(remove(ar[ar1[i].first].begin(),ar[ar1[i].first].end(),ar1[i].second),ar[ar1[i].first].end());
            ar[ar1[i].second].erase(remove(ar[ar1[i].second].begin(),ar[ar1[i].second].end(),ar1[i].first),ar[ar1[i].second].end());
            if(connected()){
                if(res.find({ar1[i].second,ar1[i].first})==res.end()){
                    res.insert(ar1[i]);
                }
            }
            ar[ar1[i].first].push_back(ar1[i].second);
            ar[ar1[i].second].push_back(ar1[i].first);
        }
        cout<<res.size()<<endl;
        for(auto x:res){
            cout<<"("<<x.first<<" "<<x.second<<") ";
        }
        cout<<endl;
    }

    return 0;
}
