#include <bits/stdc++.h>
using namespace std;
int main()
{

    long long n, m;
    cin >> n >> m;

    vector<long long> a1(n);
    vector<long long> a2(m);
    for (long long i = 0; i < n; i++)
        cin >> a1[i];
    for (long long i = 0; i < m; i++)
        cin >> a2[i];
    long long hieu = INT_MAX;
    sort(a2.begin(), a2.end());
    for (long long i = 0; i < n; i++)
    {
        auto it = lower_bound(a2.begin(), a2.end(), a1[i]);
        if (it != a2.end())
        {
            hieu = min(hieu, abs(*it - a1[i]));
        }
        if(it!=a2.begin()){
            --it;
            hieu=min(hieu,abs(*it-a1[i]));
        }
    }
    cout << hieu << endl;
    return 0;
}