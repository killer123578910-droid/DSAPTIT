#include <bits/stdc++.h>
using namespace std;
void testcase()
{
    int n, s, m;
    cin >> n >> s >> m;
    if(n<m||6*(n-m)<m){
        cout<<-1<<endl;
        return;
    }
    cout<<ceil((float)m*s/n)<<endl;
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