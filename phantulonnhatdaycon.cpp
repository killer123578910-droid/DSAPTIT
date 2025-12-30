#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n, k;

    while (t--)
    {
        cin >> n >> k;
        vector<long long> ar(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        long long maxlocal = ar[0];
        for (int i = 0; i < k; i++)
        {
            maxlocal = max(maxlocal, ar[i]);
        }
        vector<long long> res;
        res.push_back(maxlocal);
        for (int i = k; i < n; i++)
        {
            if (ar[i - k] == maxlocal)
            {
                maxlocal = ar[i - k + 1];
                for (int j = i - k + 1; j <= i; j++)
                {
                    maxlocal = max(maxlocal, ar[j]);
                }
                res.push_back(maxlocal);
            }
            else
            {
                maxlocal = max(maxlocal, ar[i]);
                res.push_back(maxlocal);
            }
        }
        for (auto x : res)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}