#include <bits/stdc++.h>
using namespace std;
#define ll long long
void testcase()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a1(n);
    vector<ll> a2(m);
    vector<ll> a3(k);
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a3[i];
    }
    long long maxid = max({n, m, k});

    vector<long long> res;
    int i = 0, j = 0, l = 0;
    while (i < n && j < m && l < k)
    {
        long long maxcur = max({a1[i], a2[j], a3[l]});
        if (a1[i] == a2[j] && a1[i] == a3[l] && a2[j] == a3[l])
        {

            res.push_back(a1[i]);
            i++;
            j++;
            l++;
        }
        else
        {
            while (i < n && a1[i] < maxcur)
            {
                i++;
            }
            while (j < m && a2[j] < maxcur)
            {
                j++;
            }
            while (l < k && a3[l] < maxcur)
            {
                l++;
            }
        }
    }
    if (res.empty())
        cout << "NO" << endl;
    else
    {
        for (auto x : res)
            cout << x << " ";
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        testcase();
    }

    return 0;
}