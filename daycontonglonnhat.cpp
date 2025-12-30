#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n, q;
    cin >> n >> q;
    int ar[n+1];
    long long prefix[n+1];
    memset(prefix,0,sizeof(prefix));

    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
            prefix[i]=prefix[i-1]+max(ar[i],0);
    }

    vector<pair<int, int>> que(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        que[i] = make_pair(x, y);
    }

    for (int i = 0; i < q; i++)
    {
        int l = que[i].first;
        int r = que[i].second;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }

    return 0;
}
