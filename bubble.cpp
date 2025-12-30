#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void testcase()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int check;
    int stt = 0;
    stack<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        check = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                check = 1;
                swap(ar[j], ar[j + 1]);
            }
        }
        if (!check)
            break;
        vector<int> temp = ar;
        stt++;
        s.push(temp);
    }
    while (!s.empty())
    {
        string str = to_string(stt--);
        cout << "Buoc " << str << ": ";
        for (auto x : s.top())
        {
            cout << x << " ";
        }
        cout << endl;
        s.pop();
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        testcase();
    }
    return 0;
}
