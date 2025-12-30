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
        unsigned long long x = 0;
        unsigned long long finale = 8;
        for (int i = 0; i < n - 1; i++)
        {
            finale = finale * 10 + 8;
        }
        vector<unsigned long long> vt;
        queue<unsigned long long> qu;
        while (x != finale)
        {
            if (!qu.empty())
            {
                x = qu.front();
                qu.pop();
                vt.push_back(x);
            }
            unsigned long long x1 = x * 10 + 6;
            qu.push(x1);
            unsigned long long x2 = x * 10 + 8;
            qu.push(x2);
        }
       cout<<vt.size()<<endl;
       for(auto x:vt) cout<<x<<" ";
       cout<<endl;
    }
    return 0;
}