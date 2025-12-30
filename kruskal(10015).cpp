#include <bits/stdc++.h>
using namespace std;
typedef struct edge
{
    int u, v, w;
    edge(){};
    edge(int k, int l, int m)
    {
        this->u = k;
        this->v = l;
        this->w = m;
    }
}edge;
int n, m;
vector<int> sz(1005);
vector<int> parent(1005);
void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find(int a)
{
    if (a == parent[a])
        return a;
    else
    {
        return parent[a] = find(parent[a]);
    }
}
bool unionn(int a, int b)
{
    int u = find(a);
    int v = find(b);
    if (u == v)
        return false;
    if (sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}
void kruskal(vector<edge> &ar){
    int d=0;
    int sc=0;
    int i=0;
    while(sc<n-1&&i<ar.size()){
        if(unionn(ar[i].u,ar[i].v)){
            sc++;
            d+=ar[i].w;
        }
        i++;
    }
    cout<<d<<endl;
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int main()
{
    int e;
    cin >> e;
    while (e--)
    {
        cin >> n >> m;
        vector<edge> ar(m);
        make_set();
        for (int i = 0; i < m; i++)
        {
            int x, y,w;
            cin >> x >> y>>w;
            edge e=edge(x,y,w);
            ar[i]=e;

        }
        sort(ar.begin(),ar.end(),cmp);
        kruskal(ar);
    }
    return 0;
}