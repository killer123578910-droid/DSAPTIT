#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}
void testcase()
{
    int d;
    int flag = 0;
    string s;
    cin>>s;
    d=2;
    map<char, int> mapl;
    vector<pair<char, int>> pq;
    for (auto x : s)
    {
        mapl[x]++;
    }
    for (auto x : mapl)
    {
        pq.push_back(make_pair(x.first, x.second));
    }
    sort(pq.begin(), pq.end(), cmp);
    int i = 0;
    int k = pq.size();
    while (i < k)
    {
        for (int t = 0; t < pq[i].second; t++)
        {
            if (i + (t * d) >= s.size())
            {
                flag = 1;
                break;
            }
        }   
        i++;
    }
    if (flag == 0)
        cout << 1 << endl;
    else
        cout << -1 << endl;
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