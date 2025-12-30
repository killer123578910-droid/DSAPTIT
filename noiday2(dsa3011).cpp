#include <bits/stdc++.h>
using namespace std;
long long base = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<int> ar(n);
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for (auto &x : ar)
            cin >> x, q.push(x);

        long long sum=0;
        long long total=0;
        while(q.size()>1){
            long long a1=q.top();q.pop();
            long long a2=q.top();q.pop();
            sum=(a1+a2)%base;
            total=(total+sum)%base;
            q.push(sum);
        }
        cout<<total<<endl;
    }
    return 0;
}