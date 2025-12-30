#include <bits/stdc++.h>
using namespace std;
int n;
int flag = 0;
string kq;
vector<vector<int>> matran(20, vector<int>(20));
set<string> str;
void Try(int i, int j)
{
    if (i == n && j == n)
    {
        flag = 1;
        cout<<kq<<" ";
        return;
    }
    if (matran[i + 1][j] == 1)
    {
        kq += "D";
        Try(i + 1, j);
        kq.erase(kq.size()-1);
    }
    if (matran[i][j + 1] == 1)
    {
        kq += "R";
        Try(i, j + 1);
        kq.erase(kq.size()-1);
    }
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> matran[i][j];
            }
        }
        if(matran[1][1]==0){
            cout<<"-1";
            cout<<endl;
            continue;
        }
        Try(1, 1);
        if (!flag)
        {
            cout << -1 << endl;
        }
        flag=0;
        cout<<endl;
        kq="";
    }
    return 0;
}