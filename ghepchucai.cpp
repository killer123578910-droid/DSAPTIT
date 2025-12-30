#include <bits/stdc++.h>
using namespace std;
char c;
char s[26];
int n;
int a[26];
int b[26];
void in()
{
    for (int i = 1; i < n - 1; i++)
    {
        if (s[a[i]] == 'A' || s[a[i]] == 'E')
        {
            if (s[a[i - 1]] != 'A' && s[a[i - 1]] != 'E' && s[a[i + 1]] != 'A' && s[a[i + 1]] != 'E')
                return;
        }
    }
    for (int i = 0; i < n; i++)
        cout << s[a[i]];
    cout << endl;
}
void quaylui(int i)
{
    for (int j = 0; j < n; j++)
    {
        if (!b[j])
        {
            b[j] = 1;
            a[i] = j;
            if (i == n - 1)
                in();
            else
                quaylui(i + 1);
            b[j] = 0;
        }
    }
}
int main()
{
    cin >> c;
    n = (c - 'A') + 1;
    char cha='A';
    for(int i=0;i<n;i++) s[i]=cha++;
    quaylui(0);
    return 0;
}