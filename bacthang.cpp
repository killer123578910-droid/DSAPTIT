#include <bits/stdc++.h>
using namespace std;
const long long modd = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                    dp[i] = (dp[i] + dp[i - j]) % modd;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}