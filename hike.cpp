#include <bits/stdc++.h>
#define endl '\n'
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

    int curRain = 0;
    for (int i = 0; i < k; i++)
    {
        if (ar[i] == 1)
        {
            curRain++;
        }
    }

    int count = 0;
    int flag = 0;
    int i = k;

    if (curRain == 0)
    {
        flag = 1;
        count++;
    }

    while (i < n)
    {
        if (flag == 1)
        {
            // Skip next k days + 1 rest day
            for (int skip = 0; skip < k + 1 && i < n; skip++, i++)
            {
                if (i - k >= 0 && ar[i - k] == 1)
                    curRain--;
                if (ar[i] == 1)
                    curRain++;
            }
            flag = 0;
            continue;
        }

        if (i - k >= 0 && ar[i - k] == 1)
            curRain--;
        if (ar[i] == 1)
            curRain++;

        if (curRain == 0)
        {
            flag = 1;
            count++;
        }

        i++;
    }

    cout << count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        testcase();
        cout << endl;
    }

    return 0;
}
