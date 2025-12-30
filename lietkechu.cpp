#include <bits/stdc++.h>
using namespace std;
int n, k;
char ar[25];
int check(char ar[])
{
    int check1 = 0, check2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ar[i] == 'A')
        {
            check1 = 1;
        }
        if (ar[i] == 'B')
        {
            check2 = 1;
        }
        if (check1 && check2)
            return 1;
    }
    return 0;
}
void in()
{
    if (check(ar))
    {
        for (int i = 1; i <= n; i++)
            cout << ar[i];
        cout << endl;
    }
}
void quaylui(int i)
{
    for (char j = 'A'; j <= 'B'; j++)
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
    return 0;
}