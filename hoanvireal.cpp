#include<bits/stdc++.h>
using namespace std;
int ar[25];
string s;
int b[100];
int n, k;
void in(){

        for (int i = 1; i <= n; i++)
            cout << ar[i] << " ";
        cout << endl;
}
void quayluihoanvi(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!b[j])
        {
            ar[i] = j;
            b[j] = 1;
            if (i == n)
                in();
            else
                quayluihoanvi(i + 1);
            b[j] = 0;
        }
    }
}
int main(){
    cin>>n;
    quayluihoanvi(1);
    return 0;
}