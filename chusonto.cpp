#include <bits/stdc++.h>
using namespace std;

int n;
int ar[25];

int snt(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void in()
{
    if (ar[n] % 2 != 0)
    {
        int flag1 = 0;
        int flag2 = 0;
        int flag3 = 0;
        int flag4 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ar[i] == 2)
                flag1 = 1;
            if (ar[i] == 3)
                flag2 = 1;
            if (ar[i] == 5)
                flag3 = 1;
            if (ar[i] == 7)
                flag4 = 1;
        }
        if (flag1 == 0 || flag2 == 0 || flag3 == 0 || flag4 == 0)
            return;
        for (int i = 1; i <= n; i++)
        {
            cout << ar[i];
        }
        cout << endl;
    }
}

void quaylui(int i)
{
    int primes[] = {2, 3, 5, 7};
    for (int j = 0; j < 4; j++)
    {
        ar[i] = primes[j];
        if (i == n)
            in();
        else
            quaylui(i + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    int i=4;
    while (t>=4)
    {
        
        n = i;
        quaylui(1);
        i++;
        t--;
    }
    return 0;
}
