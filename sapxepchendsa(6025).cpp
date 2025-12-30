#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int stt = 0;

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int mini;
    string str = to_string(stt++);
    cout << "Buoc " << str << ": ";
    cout << ar[0] << endl;
    int j;
    for (int i = 1; i < n; i++)
    {
        int key = ar[i];
        j = i - 1;
        while (j >= 0 && ar[j] > key)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
        string str = to_string(stt++);
        cout << "Buoc " << str << ": ";
        for (int k = 0; k <= i; k++)
            cout << ar[k] << " ";
        cout << endl;
    }

    return 0;
}
