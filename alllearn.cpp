#include <bits/stdc++.h>
using namespace std;
vector<int> ar1[1005];
int ar[25];
int b[100];
int n, k;
bool visited[1005];
vector<int> parent(1005);
void dfs(int i)
{
    // cout<<i<<" ";
    visited[i] = true;
    for (auto x : ar1[i])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}
void bfs(int i)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        // cout<<v<<" ";
        for (auto x : ar1[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }
}
void trackbfs(int u, int v)
{
    vector<int> res;
    memset(visited, false, sizeof(visited));
    bfs(u);
    if (!visited[v])
    {
        return;
    }
    while (v != u)
    {
        res.push_back(v);
        v = parent[v];
    }
    res.push_back(u);
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}
void in()
{
    for (int i = 1; i <= n; i++)
        cout << ar[i];
    cout << " ";
}
void ink()
{
    for (int i = 1; i <= k; i++)
        cout << ar[i];
    cout << " ";
}
void quayluinp(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        ar[i] = j;
        if (i == n)
            in();
        else
            quayluinp(i + 1);
    }
}
void quayluitohop(int i)
{
    for (int j = ar[i - 1] + 1; j <= n - k + i; j++)
    {
        ar[i] = j;
        if (i == k)
            ink();
        else
            quayluitohop(i + 1);
    }
}
void quayluihoanvi(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!b[j])
        {
            ar[i] = j;
            b[j] = 1;
            if (i == n)
                in();
            else
                quayluihoanvi(i + 1);
            b[j] = 0;
        }
    }
}
void selectionsort(vector<int> &ar)
{
    for (int i = 0; i < ar.size() - 1; i++)
    {
        int minid = i;
        for (int j = i + 1; j < ar.size(); j++)
        {
            if (ar[minid] > ar[j])
            {

                minid = j;
            }
        }
        swap(ar[minid], ar[i]);
    }
}
void insertionsort(vector<int> &ar)
{
    for (int i = 1; i < ar.size(); i++)
    {
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j] > key)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }
}
void buble(vector<int> &ar)
{
    for (int i = 0; i < ar.size() - 1; i++)
    {
        bool check = false;
        for (int j = 0; j < ar.size() - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                check = true;
                swap(ar[j], ar[j + 1]);
            }
        }
        if (!check)
            return;
    }
}
void Merge(vector<int> &ar, vector<int> &left, vector<int> &right)
{
    int l = left.size();
    int r = right.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < l && j < r)
    {
        if (left[i] < right[j])
        {
            ar[k] = left[i];
            i++;
            k++;
        }
        else
        {
            ar[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < l)
    {
        ar[k] = left[i];
        k++;
        i++;
    }
    while (j < r)
    {
        ar[k] = right[j];
        k++;
        j++;
    }
}
void mergesort(vector<int> &ar)
{
    int length = ar.size();
    if (length <= 1)
        return;
    int lef = length / 2;
    int right = length - lef;
    vector<int> left(lef);
    vector<int> righ(right);
    for (int i = 0; i < length; i++)
    {
        if (i < lef)
        {
            left[i] = ar[i];
        }
        else
        {
            righ[i - lef] = ar[i];
        }
    }
    mergesort(left);
    mergesort(righ);
    Merge(ar, left, righ);
}
void testsort()
{
    vector<int> ar(10);
    for (int i = 0; i < 10; i++)
        cin >> ar[i];
    mergesort(ar);
    for (int i = 0; i < 10; i++)
        cout << ar[i] << " ";
}
void testrecur()
{
    cin >> n >> k;
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++)
    {
        ar[i] = i;
    }
}
void testgraph()
{

    memset(visited, false, sizeof(visited));
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        ar1[x].push_back(y);
        ar1[y].push_back(x);
    }
    trackbfs(1, 4);
}
int lcs(vector<int> a1, vector<int> a2)
{
    int a = a1.size();
    int b = a2.size();
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (a1[i - 1] == a2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[a][b];
}
void testlcs()
{
    int n, m;
    cin >> n >> m;
    vector<int> a1(n);
    vector<int> a2(m);
    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < m; i++)
        cin >> a2[i];
    cout << lcs(a1, a2);
}
int lis(vector<int> a1)
{
    int length = a1.size();
    vector<int> dp(length + 1, 1);
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a1[j] < a1[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
void testlis()
{
    int m;
    cin >> m;
    vector<int> a1(m);
    for (int i = 0; i < m; i++)
        cin >> a1[i];
    cout << lis(a1) << endl;
}
int caitui(int v[], int w[], int n, int wt)
{
    vector<vector<int>> dp(n+1,vector<int>(wt+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=wt;j++){
            if(w[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
            }
        }
    }
    return dp[n][wt];
}
void testcaitui(){
    int n;
    int wt;
    cin>>n>>wt;
    int v[n];
    int w[n];
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<caitui(v,w,n,wt)<<endl;
}
int main()
{
    testcaitui();
}