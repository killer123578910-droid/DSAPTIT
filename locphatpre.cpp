#include <bits/stdc++.h>
using namespace std;
int n, k, ar[25];
int countt = 0;
set<string> setl;
void in()
{
    int warning = 0;
    if (ar[1] != 8 || ar[n] != 6)
        return;
    int consecutive_six = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ar[i] == 6)
        {
            consecutive_six++;
            if (consecutive_six >= 4)
                return; // Invalid: 4 or more consecutive 6s
        }
        else
        {
            consecutive_six = 0; // Reset counter if not 6
        }

        // Check for consecutive 8s
        if (i < n && ar[i] == 8 && ar[i + 1] == 8)
            return;
    }

    string temp;
    for (int i = 1; i <= n; i++)
        temp += to_string(ar[i]);
    setl.insert(temp);
}
void quaylui(int i)
{
    for (int j = 6; j <= 8; j += 2)
    {
        ar[i] = j;
        if (i == n)
            in();
        else
            quaylui(i + 1);
    }
}
int main()
{
    cin >> n;
    quaylui(1);
    for (auto x : setl)
        cout << x << endl;
    return 0;
}