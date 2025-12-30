#include <bits/stdc++.h>
using namespace std;
void solution()
{
    int n;
    cin >> n;
    long long ar1[n];
    long long ar2[n - 1];
    unordered_map<long long, int> mapl;
    for (int i = 0; i < n; i++)
    {
        cin >> ar1[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> ar2[i];
        mapl[ar2[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (!mapl[ar1[i]])
        {
            cout << i + 1 << endl;
            break;
        }else mapl[ar1[i]]--;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}