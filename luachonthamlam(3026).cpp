#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int s;
    cin >> n >> s;
    if (s > 9 * n||s<=0)
        cout << -1<<" "<<-1;
    else
    {   
        int sum=s;
        int a[n] = {1}; s--;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = min(9, s);
            a[i] += x;
            s -= x;
            if(s==0) break;
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout<<" ";
        int ar[n]={0};
        for(int i=0;i<n;i++){
            ar[i]+=min(9,sum);
            sum-=min(9,sum);
            if(sum==0) break;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ar[i];
        }
    }

    return 0;
}