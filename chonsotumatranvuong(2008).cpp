#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> x(120, 0);
vector<vector<int>> ar(120, vector<int>(120));
vector<bool> b(120, false);
vector<vector<int>> kq;
int cursum = 0;
void ql(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!b[j])
        {
            b[j] = true;
            x[i] = j;
            cursum += ar[i][j];
            if (i == n)
            {
                if (cursum == k)
                    kq.push_back(x);
            }
            else if (cursum < k)
            {
                ql(i + 1);
            }
            cursum -= ar[i][j];
            b[j]=false;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
        }
    }
    ql(1);
    cout << kq.size() << endl;
    for (int i = 0; i < kq.size(); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << kq[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}