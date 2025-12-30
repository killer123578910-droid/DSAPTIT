#include <bits/stdc++.h>
using namespace std;
int cont = 0;
void TRY(int i, int j, vector<vector<int>> &ar, int n, int m)
{
    if (i >= n || j >= m)
        return;
    if (i == n - 1 && j == m - 1)
    {
        cont++;
        return;
    }
    TRY(i + 1, j, ar, n, m);
    TRY(i, j + 1, ar, n, m);
}

void tesecase()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ar(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> ar[i][j];
    }
    TRY(0, 0, ar, n, m);
    cout << cont << endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        tesecase();
        cont=0;
    }
    return 0;
}