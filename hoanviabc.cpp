#include <bits/stdc++.h>
using namespace std;
vector<char> ar(25);
vector<int> b(25, 0);
int n;
void in()
{
    int cnta = 0;
    int cntb = 0;
    int cntc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ar[i] == 'A')
            cnta++;
        if (ar[i] == 'B')
            cntb++;
        if (ar[i] == 'C')
            cntc++;
    }
    if ((cnta!=0 && cntb !=0 && cntc!=0) && (cnta <= cntb && cntb <= cntc&&cnta<=cntc))
    {
        for (int i = 1; i <= n; i++)
        {
            cout << ar[i];
        }
        cout << endl;
    }
}
void quaylui(int i)
{
    for (char j = 'A'; j <= 'C'; j++)
    {
        //if (b[j] == 0)
        //{
            //b[j] = 1;
            ar[i] = j;
            if (i == n)
                in();
            else
                quaylui(i + 1);
            //b[j] = 0;
       // }
    }
}
int main()
{
    int t;
    cin>>t;
    n=3;
    while(n<=t){
        quaylui(1);
        n++;
    }
    return 0;
}
