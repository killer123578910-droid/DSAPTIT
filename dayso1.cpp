#include <bits/stdc++.h>
using namespace std;

void tamgiac(int n, vector<int> &a)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = a[i] + a[i + 1];
    }
    n--;
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << "]";
    cout << endl;
    tamgiac(n, a);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        cout << "[";
        for (int i = 0; i < n; i++)
        {
            cout << ar[i];
            if (i != n - 1)
                cout << " ";
        }
        cout << "]";
        cout << endl;
        tamgiac(n, ar);
    }
    return 0;
}