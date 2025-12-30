#include <bits/stdc++.h>
using namespace std;
void solution()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    bool visited[n];
    memset(visited, true, sizeof(visited));
    vector<long long> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        visited[i] = false;
    }

    vector<long long> ar1[n];
    int j = 0;
    while (1)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            break;
        long long v;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                v = ar[i];
                visited[i] = true;
                ar1[j].push_back(v);
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && v < ar[i])
            {
                v = ar[i];
                visited[i] = true;
                ar1[j].push_back(v);
            }
        }
        j++;
    }
    cout << j << endl;
    for (int i = 0; i < j; i++)
    {
        for (auto x : ar1[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
int main()
{   
    
    solution();
    return 0;
}