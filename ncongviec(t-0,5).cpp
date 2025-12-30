#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, T;
    cin >> n;
    T=1e9;
    vector<long long> a(n + 1);
    vector<long long> c(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        long long x, y;
        cin >> x >> y;
        a[i] = x;

        c[i] = y;
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(T + 1, 0));
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 0; j <= T; j++)
        {
            if (a[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], c[i] + dp[i - 1][j - a[i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }  
    cout<<dp[n][T];
 

    return 0;
}