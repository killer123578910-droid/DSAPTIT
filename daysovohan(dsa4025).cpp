#include <bits/stdc++.h>
using namespace std;
const long long modd = 1e9 + 7;
vector<vector<long long>> donvi(2, vector<long long>(2, 1));
vector<vector<long long>> donvi1(2, vector<long long>(2, 0));

vector<vector<long long>> multi(vector<vector<long long>> &v1, vector<vector<long long>> &v2)
{
    vector<vector<long long>> res(2, vector<long long>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res[i][j] = (res[i][j] % modd + (v1[i][k] * v2[k][j]) % modd) % modd;
            }
        }
    }
    return res;
}
void init()
{
    donvi[1][1] = 0;
    for (int i = 0; i < 2; i++)
    {
        donvi1[i][i] = 1;
    }
}
vector<vector<long long>> luythua(vector<vector<long long>> d, long long k)
{
    if (k == 0)
        return donvi1;
    vector<vector<long long>> kq = luythua(d, k / 2);
    if (k % 2 == 0)
    {
        return multi(kq, kq);
    }
    else
    {
        vector<vector<long long>> re = multi(kq, kq);
        return multi(d, re);
    }
}
void testcase()
{
    long long k;
    cin >> k;
    vector<vector<long long>> temp = luythua(donvi, k);
    cout << temp[0][1] << endl;
}
int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        testcase();
    }
    return 0;
}