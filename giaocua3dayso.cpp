#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l;
        cin >> n >> m >> l;
        vector<long long> ar1(n), ar2(m), ar(l), res;
        for (auto &x : ar1)
        {
            cin >> x;
        }
        for (auto &x : ar2)
        {
            cin >> x;
        }
        for (auto &x : ar)
        {
            cin >> x;
        }
        long long i = 0, j = 0, k = 0;
        while (i < n && j < m && k < l)
        {
            if (ar1[i] == ar2[j] && ar2[j] == ar[k])
            {
                res.push_back(ar1[i]);
                i++;
                j++;
                k++;
            }
            else if (ar1[i] > ar2[j])
                j++;
            else if (ar2[j] > ar[k])
                k++;
            else
                i++;
        }
        if (res.empty())
            cout << -1 << endl;
        else
        {
            for (auto x : res)
                cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}