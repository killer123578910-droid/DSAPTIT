#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long long ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int q[m];
    for (int i = 0; i < m; i++)
        cin >> q[i];
    for (int k = 0; k < m; k++)
    {
        vector<int> dp(n + 1, 1);
        for (int i = q[k]; i < n; i++)
        {
            for (int j = q[k] - 1; j < i; j++)
            {
                if (ar[j] < ar[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        cout << *max_element(dp.begin(), dp.end())-1 << endl;
    }

    return 0;
}