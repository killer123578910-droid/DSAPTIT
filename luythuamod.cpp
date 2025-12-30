#include <bits/stdc++.h>
using namespace std;
long long modd = 1e9 + 7;
long long ex(long long a, long long n)
{
    if (n == 0)
        return 1;
    long long x = ex(a, n / 2);
    if (n % 2 == 0)
        return (x*x)%modd;
    return (a * ((x*x)%modd)) % modd;
}
long long daoso(long long n) {
    long long ans = 0;
    while (n > 0) {
        ans = ans * 10 + (n % 10);
        n /= 10;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    long long a;
    long long n;
    while (t--)
    {
        cin >> a;
        long long dao = daoso(a);
        cout << ex(a, dao) << endl;
    }
    return 0;
}