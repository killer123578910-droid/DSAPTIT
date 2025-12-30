#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a1(n), a2(n - 1);
        unordered_map<long long, int> mapl;
        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a2[i];
            mapl[a2[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mapl[a1[i]] == 0)
            {
                cout << i + 1;
                break;
            }
            mapl[a1[i]]--;
        }
        cout << endl;
    }
    return 0;
}