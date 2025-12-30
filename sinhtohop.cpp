#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> A(25);
void in()
{
        string s;
        for (int i = 1; i <= k; i++)
        {
            s+=to_string(A[i]);
        }
        cout<<s<<" ";
    
}
void quaylui(int i)
{
    for (int j = A[i - 1] + 1; j <= n - k + i; j++)
    {
        A[i] = j;
        if (i == k)
            in();
        else
            quaylui(i + 1);
    }
}
int main()
{   int t;
    cin>>t;
    while(t--){
    cin >> n >> k;
    quaylui(1);
    A.clear();
    cout<<endl;
    }
    return 0;
}