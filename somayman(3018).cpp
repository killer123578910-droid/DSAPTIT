#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int y;
        int x;
        int flag = 1;
        for (y = n/7; y >=0; y--)
        {
            if ((n - 7 * y) % 4 == 0)
            {
                x = (n - 7 * y) / 4;
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < x; i++)
                cout << 4;
            for (int i = 0; i < y; i++)
                cout << 7;
            cout << endl;
        }
    }
    return 0;
}