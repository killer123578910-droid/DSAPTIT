#include <bits/stdc++.h>
using namespace std;
vector<string> st(31);
int ar[31];
int n;
int k;
set<string> setl;
void in()
{
    int flag = 1;
    for (int i = 1; i < k; i++)
    {
        if (st[ar[i]] == st[ar[i + 1]])
        {
           return;
        }
    }
   
        string temp;
        for (int i = 1; i <= k; i++)
        {
            temp += st[ar[i]] + " ";
        }
        setl.insert(temp);  
}
void quaylui(int i)
{
    for (int j = ar[i - 1] + 1; j <= n - k + i; j++)
    {
        ar[i] = j;
        if (i == k)
            in();
        else
            quaylui(i + 1);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> st[i];
    sort(st.begin() + 1, st.begin() + n + 1);
    ar[0] = 0;
    quaylui(1);
    for (auto x : setl)
        cout << x << endl;
    return 0;
}