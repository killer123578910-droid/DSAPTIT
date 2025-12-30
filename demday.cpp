// demday: mình tách số n thằng tổng của các số bé hơn n: vidiu n=4; tách nhỏ nhât dc 1 +1 +1+ 1 thì có 3 vị trí có thể đặt được dấu cộng.
//  ở mỗi dấu cộng, lại có thể có 2 lựa chọn không cộng hoặc cộng, => 3 dấu cộng khả dĩ, thì có 2^4-1 cách để tạo các dãy.
// thử với các số n khác => công thức là 2^n-1 cách tạo dãy;
#include <bits/stdc++.h>
using namespace std;
const long long modd = 123456789;
long long expo(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long x = expo(a, b / 2);
    if (b % 2 == 0)
    {
        return (x * x) % modd;
    }
    return (a * ((x * x) % modd)) % modd;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << expo(2, n-1) << endl;
    }
    return 0;
}