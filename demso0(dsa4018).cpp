#include <bits/stdc++.h>
using namespace std;
int sovle(vector<int> ar, int start, int end)
{
    int mid = (start + end) / 2;
    if (ar[mid] == 1)
    {
        if (ar[mid - 1] == 1)
        {
            return sovle(ar, start, mid - 1);
        }
        else
        {
            return mid;
        }
    }
    else
    {
        return sovle(ar, mid + 1, end);
    }
}
void testcase()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    if (ar[n - 1] == 0)
        cout << n << endl;
    else if (ar[0] == 1)
        cout << 0 << endl;
    else
    {
        cout << sovle(ar, 0, n - 1) << endl;
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