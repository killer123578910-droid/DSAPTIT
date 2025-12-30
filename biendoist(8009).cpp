#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> s >> n;
        queue<long long> q;
        vector<int> dist(10002, -1);
        dist[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            if (k == n)
            {
                break;
            }
            if (k - 1 >= 0 && dist[k - 1] == -1)
            {
                dist[k - 1] = dist[k] + 1;
                q.push(k - 1);
            }
            if (k * 2 <= 10002 && dist[k * 2] == -1)
            {
                dist[k * 2] = dist[k] + 1;
                q.push(k * 2);
            }
        }
        cout << dist[n] << endl;
    }
    return 0;
}