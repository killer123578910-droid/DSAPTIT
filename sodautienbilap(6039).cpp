#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, long long> x, pair<int, long long> y)
{
    return x.second < y.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, long long>> ar(n);
        vector<long long> b(n);
        int i = 0;
        for (auto &x : ar)
        {
            cin >> x.second;
            b[i] = x.second;
            x.first = i++;
        }

        sort(ar.begin(), ar.end(), cmp);
        int minidx = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            if (ar[i].second == ar[i + 1].second)
            {
                minidx = min({minidx, ar[i].first});
            }
            else if (i > 0 && ar[i].second == ar[i - 1].second)
                minidx = min(minidx, ar[i].first);
        }
        cout << endl;
        if (minidx == INT_MAX)
            cout << "NO" << endl;
        else
            cout << b[minidx] << endl;
    }
    return 0;
}