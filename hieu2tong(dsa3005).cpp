#include <bits/stdc++.h>
using namespace std;
void testcase()
{
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    long long n1 = 0;
    long long n2 = 0;
    if (n - k >= k)
    {
        for (int i = 0; i < n; i++)
        {
            if (i < k)
            {
                n1 += ar[i];
            }
            else
            {
                n2 += ar[i];
            }
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (k > 0)
            {
                n1 += ar[i];
                k--;
            }
            else
            {
                n2 += ar[i];
            }
        }
    }
    cout << abs(n1 - n2) << endl;
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