#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    vector<int> chan;
    vector<int> le;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] % 2 == 0)
        {
            chan.push_back(ar[i]);
        }
        else
        {
            le.push_back(ar[i]);
        }
    }
    sort(chan.begin(),chan.end());
    sort(le.begin(), le.end(), cmp);
    int j = 0;
    int k = 0;
    int flag = 0;
     for (int i = 0; i < n; i++)
    {
        if(ar[i]%2==0){
            cout<<chan[j++]<<" ";
        }else{
            cout<<le[k++]<<" ";
        }
    }
    return 0;
}